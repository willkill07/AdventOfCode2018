#include "Solution.hpp"

#include <limits>
#include <set>
#include <vector>
#include <unordered_map>

#include <range/v3/algorithm.hpp>
#include <range/v3/getlines.hpp>
#include <range/v3/numeric.hpp>
#include <range/v3/view/chunk.hpp>
#include <range/v3/view/indices.hpp>
#include <range/v3/view/repeat.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/zip.hpp>

#include <iomanip>

std::unordered_map<long long, char> OCR = {
  {0b111110'100001'100001'100001'111110'100001'100001'100001'100001'111110, 'B'},
  {0b011110'100001'100000'100000'100000'100000'100000'100000'100001'011110, 'C'},
  {0b011110'100001'100000'100000'100000'100111'100001'100001'100011'011101, 'G'},
  {0b100001'100001'100001'100001'111111'100001'100001'100001'100001'100001, 'H'},
  {0b000111'000010'000010'000010'000010'000010'000010'100010'100010'011100, 'J'},
  {0b100000'100000'100000'100000'100000'100000'100000'100000'100000'111111, 'L'},
  {0b100001'110001'110001'101001'101001'100101'100101'100011'100011'100001, 'N'},
  {0b111110'100001'100001'100001'111110'100000'100000'100000'100000'100000, 'P'}
};

struct point {
  long long x, y;
};

struct particle {
  point pos{0,0}, vel{0,0};
  static auto eval(int t) {
    return [t](particle const& p) -> point {
      return {p.pos.x + p.vel.x * t, p.pos.y + p.vel.y * t};
    };
  }
};

struct box {
  using lim = std::numeric_limits<long long>;
  point min {lim::max(), lim::max()} , max {lim::min(), lim::min()};
  long long width() const {
    return std::abs(max.x - min.x + 1);
  }
  long long height() const {
    return std::abs(max.y - min.y + 1);
  }
  long long area() const {
    return width() * height();
  }
  static box update(box const& b, point const& p) {
    auto [x, y] = p;
    box n;
    n.min = {std::min(b.min.x, x), std::min(b.min.y, y)};
    n.max = {std::max(b.max.x, x), std::max(b.max.y, y)};
    return n;
  }

  unsigned index(point const& p) const {
    auto [x, y] = p;
    return (x - min.x) + (y - min.y) * width();
  }
};

template <>
template <bool part2>
void
Day<10>::solve(std::istream& is, std::ostream& os) {
  std::vector<particle> particles;
  int tMax {0}, tMin {std::numeric_limits<int>::max()};
  for (auto const& line : ranges::getlines(is)) {
    particle p;
    sscanf(line.c_str(), "position=<%lld,%lld> velocity=<%lld,%lld>", &p.pos.x, &p.pos.y, &p.vel.x, &p.vel.y);
    int x = std::abs(p.pos.x / p.vel.x);
    int y = std::abs(p.pos.y / p.vel.y);
    tMin = std::min({tMin, x, y});
    tMax = std::max({tMax, x, y});
    particles.push_back(p);
  }

  using namespace ranges::view;

  auto area = [](auto const& a) { return std::get<1>(a).area(); };
  auto findMinTime = [&](auto t) {
    return std::pair(t, ranges::accumulate(particles | transform(particle::eval(t)), box {}, &box::update));
  };

  auto [minTime, rect] = ranges::min(closed_iota(tMin, tMax) | transform(findMinTime), std::less<>{}, area);
  if constexpr (part2) {
    os << minTime << '\n';
    return;
  }

  std::vector<int> grid(rect.area(), 0);
  auto eval = particle::eval(minTime);
  for (auto const & p : particles) {
    grid[rect.index(eval(p))] = 1;
  }

  std::array<long long, 8> chars = { 0 };
  for (auto&& [y, row] : zip(indices, grid | chunk(rect.width()))) {
    for (auto && [i, cells] : zip(indices, row | chunk(8))) {
      for (auto && [x, c] : zip(indices, cells) | take(6)) {
        if (c == 1) {
          chars[i] |= static_cast<long long>(c) << (59 - (x + y * 6));
        }
      }
    }
  }
  for (auto c : chars) {
    os << OCR.at(c);
  }
  os << '\n';
}

template void
Day<10>::solve<true>(std::istream&, std::ostream&);
template void
Day<10>::solve<false>(std::istream&, std::ostream&);
