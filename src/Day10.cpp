#include "Solution.hpp"

#include <limits>
#include <unordered_map>
#include <vector>

#include <range/v3/all.hpp>

namespace view = ranges::view;

static std::unordered_map<long long, char> const OCR =
  {{0b001100'010010'100001'100001'100001'111111'100001'100001'100001'100001, 'A'},
   {0b111110'100001'100001'100001'111110'100001'100001'100001'100001'111110, 'B'},
   {0b011110'100001'100000'100000'100000'100000'100000'100000'100001'011110, 'C'},
   {0b111111'100000'100000'100000'111110'100000'100000'100000'100000'111111, 'E'},
   {0b111111'100000'100000'100000'111110'100000'100000'100000'100000'100000, 'F'},
   {0b011110'100001'100000'100000'100000'100111'100001'100001'100011'011101, 'G'},
   {0b100001'100001'100001'100001'111111'100001'100001'100001'100001'100001, 'H'},
   {0b000111'000010'000010'000010'000010'000010'000010'100010'100010'011100, 'J'},
   {0b100001'100010'100100'101000'110000'110000'101000'100100'100010'100001, 'K'},
   {0b100000'100000'100000'100000'100000'100000'100000'100000'100000'111111, 'L'},
   {0b100001'110001'110001'101001'101001'100101'100101'100011'100011'100001, 'N'},
   {0b111110'100001'100001'100001'111110'100000'100000'100000'100000'100000, 'P'},
   {0b111110'100001'100001'100001'111110'100100'100010'100010'100001'100001, 'R'},
   {0b100001'100001'010010'010010'001100'001100'010010'010010'100001'100001, 'X'},
   {0b111111'000001'000001'000010'000100'001000'010000'100000'100000'111111, 'Z'}};

struct point {
  long long x, y;
};

struct particle {
  point pos {0, 0}, vel {0, 0};
  static auto eval(int t) {
    return [t](particle const& p) -> point {
      return {p.pos.x + p.vel.x * t, p.pos.y + p.vel.y * t};
    };
  }
};

struct box {
  using lim = std::numeric_limits<long long>;
  point min {lim::max(), lim::max()}, max {lim::min(), lim::min()};
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
  auto area = [](auto const& a) { return std::get<1>(a).area(); };
  auto findMinTime = [&](auto t) {
    return std::pair(t, ranges::accumulate(particles | view::transform(particle::eval(t)), box {}, &box::update));
  };
  auto const [minTime, rect] = ranges::min(view::closed_iota(tMin, tMax) | view::transform(findMinTime), std::less<>{}, area);
  if constexpr (part2) {
    os << minTime << '\n';
    return;
  }
  std::vector<int> grid(rect.area(), 0);
  for (auto const& p : particles | view::transform(particle::eval(minTime))) {
    grid[rect.index(p)] = 1;
  }
  std::vector<long long> chars((rect.width() + 2) / 8);
  for (auto&& [y, row] : view::zip(view::indices, grid | view::chunk(rect.width()))) {
    for (auto&& [i, cells] : view::zip(view::indices, row | view::chunk(8))) {
      for (auto&& [x, c] : view::zip(view::indices, cells) | view::take(6)) {
        chars[i] |= static_cast<long long>(c) << (59 - (x + y * 6));
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
