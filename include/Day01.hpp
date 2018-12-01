#include <iterator>
#include <numeric>
#include <unordered_set>
#include <vector>

#include "Solution.hpp"

template <>
template <bool part2>
void
Day<1>::solve(std::istream &is, std::ostream &os) {
  std::vector<int> data(std::istream_iterator<int>(is), {});
  if constexpr (!part2) {
    os << std::accumulate(data.begin(), data.end(), 0) << '\n';
    return;
  }
  int sum{0};
  std::unordered_set<int> uniq;
  while (true) {
    for (auto v : data) {
      if (!uniq.insert(sum += v).second) {
        os << sum << '\n';
        return;
      }
    }
  }
}
