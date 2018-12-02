#include "Solution.hpp"
#include "util.hpp"

#include <algorithm>
#include <array>
#include <iterator>
#include <numeric>
#include <unordered_map>
#include <vector>

auto &
count(std::string const &s) {
  static std::array<int, 26> m;
  m.fill(0);
  for (auto const c : s) {
    ++m[c - 'a'];
  }
  static std::unordered_map<int, int> counts;
  counts.clear();
  for (auto const c : m) {
    ++counts[c];
  }
  return counts;
}

std::optional<std::string>
check(std::string const &a, std::string const &b) {
  int diff = std::inner_product(std::begin(a), std::end(a), std::begin(b), 0, std::plus<>{}, std::not_equal_to<>{});
  if (diff == 1) {
    std::string s (a);
    auto [diffS, _] = std::mismatch(std::begin(s), std::end(s), std::begin(b));
    s.erase(diffS);
    return s;
  }
  return std::nullopt;
}

template <>
template <bool part2>
void
Day<2>::solve(std::istream &is, std::ostream &os) {
  std::vector<std::string> data(std::istream_iterator<std::string>(is), {});
  if constexpr (part2) {
      auto result = combinations(data, 2,
                                 [] (auto const & l) {
                                   return check(l[0], l[1]);
                                 });
      os << *result << '\n';
  } else {
    int twos{0}, threes{0};
    for (std::string const &s : data) {
      auto const &counts = count(s);
      twos += counts.count(2);
      threes += counts.count(3);
    }
    os << (twos * threes) << '\n';
  }
}
