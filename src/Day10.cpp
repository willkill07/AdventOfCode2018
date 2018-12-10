#include "Solution.hpp"

#include <limits>
#include <set>
#include <vector>

#include <range/v3/algorithm/min.hpp>
#include <range/v3/getlines.hpp>
#include <range/v3/numeric.hpp>
#include <range/v3/view/indices.hpp>
#include <range/v3/view/transform.hpp>

using ranges::view::closed_iota;
using ranges::view::transform;

using Long = std::numeric_limits<long long>;

struct point {
  long long x, y;

  bool
  operator==(point const& p) const {
    return x == p.x && y == p.y;
  }

  bool
  operator<(point const& b) const {
    if (y != b.y)
      return y < b.y;
    return x < b.x;
  }
};

struct particle {
  point pos, vel;
};

struct box {
  long long xMin{Long::max()}, xMax{Long::min()}, yMin{Long::max()}, yMax{Long::min()};

  long long
  area() const {
    return (xMax - xMin) * (yMax - yMin);
  }

  template <typename Point>
  void
  update(Point const& p) {
    auto [x, y] = p;
    xMin = std::min(xMin, x);
    xMax = std::max(xMax, x);
    yMin = std::min(yMin, y);
    yMax = std::max(yMax, y);
  }
};

template <>
template <bool part2>
void
Day<10>::solve(std::istream& is, std::ostream& os) {
  std::vector<particle> particles;
  int tMax{0}, tMin{std::numeric_limits<int>::max()};
  for (auto const& line : ranges::getlines(is)) {
    particle p;
    sscanf(line.c_str(), "position=<%lld,%lld> velocity=<%lld,%lld>", &p.pos.x, &p.pos.y, &p.vel.x, &p.vel.y);
    if (p.vel.y != 0) {
      int ty = std::abs(p.pos.y / p.vel.y);
      tMin = std::min(tMin, ty);
      tMax = std::max(tMax, ty);
    }
    if (p.vel.x != 0) {
      int tx = std::abs(p.pos.x / p.vel.x);
      tMin = std::min(tMin, tx);
      tMax = std::max(tMax, tx);
    }
    particles.push_back(p);
  }

  auto eval = [](int t) {
    return [t](particle const& p) -> point { return {p.pos.x + p.vel.x * t, p.pos.y + p.vel.y * t}; };
  };

  auto [minTime, rect] = ranges::min(closed_iota(tMin, tMax) | transform([&](auto t) {
                                       box b;
                                       for (auto const& p : particles | transform(eval(t))) {
                                         b.update(p);
                                       }
                                       return std::pair(t, b);
                                     }),
                                     std::less<>{},
                                     [](auto const& a) { return std::get<1>(a).area(); });
  if constexpr (part2) {
    os << minTime << '\n';
    return;
  }
  std::set<point> loc(particles | transform(eval(minTime)));
  os << '\n';
  auto i = loc.begin();
  for (auto const y : closed_iota(rect.yMin, rect.yMax)) {
    for (auto const x : closed_iota(rect.xMin, rect.xMax)) {
      if (i != loc.end() && *i == point{x, y}) {
        os << '*';
        ++i;
      } else {
        os << ' ';
      }
    }
    os << '\n';
  }
}

template void
Day<10>::solve<true>(std::istream&, std::ostream&);
template void
Day<10>::solve<false>(std::istream&, std::ostream&);
