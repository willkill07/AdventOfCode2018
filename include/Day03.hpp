#include "Solution.hpp"

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

#include <range/v3/all.hpp>

struct box {
  int id, x, y, w, h;

  static int
  index(std::tuple<int, int> const t) {
    auto [x, y] = t;
    return x << 16 | y;
  }

  auto
  cells () const {
    using namespace ranges::view;
    return cartesian_product(iota(x) | take_exactly(w), iota(y) | take_exactly(h));
  }

  void
  mark(std::unordered_map<int, int>& g) const {
    for (auto i : cells() | ranges::view::transform(box::index)) {
      ++g[i];
    }
  }

  bool
  clean(std::unordered_map<int, int> const& g) const {
    using namespace ranges::view;
    int s {ranges::accumulate (
             cells()
             | take_while([&](auto i) { return g.at(box::index(i)) == 1; })
             | transform([] (auto) { return 1; })
             , 0)};
    return s == (w * h);
  }
};

template <>
template <bool part2>
void
Day<3>::solve(std::istream& is, std::ostream& os) {
  std::unordered_map<int, int> grid;
  std::vector<box> boxes;
  for (std::string line; std::getline(is, line);) {
    box b;
    sscanf(line.c_str(), "#%d @ %d,%d: %dx%d", &b.id, &b.x, &b.y, &b.w, &b.h);
    boxes.push_back(b);
  }
  for (auto const& b : boxes) {
    b.mark(grid);
  }
  if constexpr (part2) {
    for (auto const& b : boxes) {
      if (b.clean(grid)) {
        os << b.id << '\n';
        return;
      }
    }
  } else {
    os << ranges::count_if(grid, [](auto const& c) { return c.second > 1; }) << '\n';
  }
}
