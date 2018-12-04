#include <iterator>
#include <unordered_set>
#include <vector>

#include <range/v3/numeric.hpp>
#include <range/v3/view/cycle.hpp>

#include "Solution.hpp"

template <>
template <bool part2>
void
Day<1>::solve(std::istream &is, std::ostream &os) {
  std::vector<int> data(std::istream_iterator<int>(is), {});
  if constexpr (!part2) {
    os << ranges::accumulate(data, 0) << '\n';
    return;
  }
  int sum{0};
  std::unordered_set<int> uniq;
  for (int const v : ranges::view::cycle(data)) {
    if (auto [_, u] = uniq.insert(sum += v); !u) {
      os << sum << '\n';
      break;
    }
  }
}

template void Day<1>::solve<true>(std::istream&, std::ostream&);
template void Day<1>::solve<false>(std::istream&, std::ostream&);
