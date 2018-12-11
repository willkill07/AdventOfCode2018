#include "Solution.hpp"

#include <array>
#include <range/v3/algorithm/max.hpp>
#include <range/v3/view/cartesian_product.hpp>
#include <range/v3/view/indices.hpp>
#include <range/v3/view/join.hpp>
#include <range/v3/view/transform.hpp>

namespace view = ranges::view;

static constexpr int SIZE = 300;

struct data {
  int power, x, y, size;
};

template <>
template <bool part2>
void
Day<11>::solve(std::istream &is, std::ostream &os) {
  std::array<std::array<int, SIZE + 1>, SIZE + 1> grid;
  grid.fill({0});
  int serial = *std::istream_iterator<int>(is);
  for (auto [y, x] : view::cartesian_product(view::closed_iota(1, SIZE), view::closed_iota(1, SIZE))) {
    int pow = ((x + 10) * ((x + 10) * y + serial) / 100 % 10) - 5;
    grid[y][x] = pow + grid[y - 1][x] + grid[y][x - 1] - grid[y - 1][x - 1];
  }

  auto blocksForSize = [](auto const &s) {
    return view::cartesian_product(view::closed_iota(s, SIZE), view::closed_iota(s, SIZE), view::single(s));
  };

  auto searchDomain = [&] {
    if constexpr (part2) {
      return view::closed_iota(1, SIZE) | view::transform(blocksForSize) | view::join;
    } else {
      return blocksForSize(3);
    }
  }();

  auto blockSum = [&](auto const &p) -> data {
    auto [y, x, s] = p;
    int pow = grid[y][x] - grid[y - s][x] - grid[y][x - s] + grid[y - s][x - s];
    return {pow, x - s + 1, y - s + 1, s};
  };

  auto best = ranges::max(searchDomain | view::transform(blockSum), std::less<>{}, &data::power);

  if constexpr (part2) {
    os << best.x << ',' << best.y << ',' << best.size << '\n';
  } else {
    os << best.x << ',' << best.y << '\n';
  }
}

template void
Day<11>::solve<true>(std::istream &, std::ostream &);
template void
Day<11>::solve<false>(std::istream &, std::ostream &);
