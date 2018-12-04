#include "Solution.hpp"

#include <algorithm>
#include <string>
#include <vector>

#include <range/v3/all.hpp>
namespace view = ranges::view;

struct box {
  int id, x, y, w, h;
  box(std::string const& s) {
    sscanf(s.c_str(), "#%d @ %d,%d: %dx%d", &id, &x, &y, &w, &h);
  }
  auto
  space() const {
    return view::cartesian_product(view::iota(x, x + w), view::iota(y, y + h));
  }
};

box
make_box(std::string const& s) {
  return {s};
}

template <typename Mat>
auto
clean(Mat& grid) {
  return [&](auto const& box) {
    auto equals_one = [&](auto const& point) { return grid(point) == 1; };
    auto one = [](auto const&) { return 1; };
    int ones = ranges::accumulate(box.space() | view::take_while(equals_one) | view::transform(one), 0);
    return ones == (box.w * box.h);
  };
}

template <>
template <bool part2>
void
Day<3>::solve(std::istream& is, std::ostream& os) {
  auto grid = [v = std::vector<int>(1'000'000)](auto const& p) mutable -> int& {
    auto [x, y] = p;
    return v[y * 1000 + x];
  };
  std::vector<box> boxes(ranges::getlines(is) | view::transform(make_box));
  for (auto const& point : view::join(boxes | view::transform(&box::space))) {
    ++grid(point);
  }
  if constexpr (part2) {
    auto b = boxes | view::filter(clean(grid));
    os << ranges::begin(b)->id << '\n';
  } else {
    auto all_cells = view::cartesian_product(view::iota(0, 1'000), view::iota(0, 1'000));
    auto greater_than_one = [&](auto const& p) { return grid(p) > 1; };
    os << ranges::count_if(all_cells, greater_than_one) << '\n';
  }
}
