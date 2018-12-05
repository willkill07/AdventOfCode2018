#include "Solution.hpp"

#include <vector>

#include <range/v3/algorithm/min.hpp>
#include <range/v3/view/filter.hpp>
#include <range/v3/view/iota.hpp>
#include <range/v3/view/transform.hpp>

namespace view = ranges::view;

int
react(std::string s) {
  std::vector<char> l;
  for (char c : s) {
    if (l.empty()) {
      l.push_back(c);
      continue;
    }
    if (char last = l.back(); abs(last - c) == abs('A' - 'a')) {
      l.pop_back();
    } else {
      l.push_back(c);
    }
  }
  return l.size();
}

template <>
template <bool part2>
void
Day<5>::solve(std::istream &is, std::ostream &os) {
  std::string s{std::istream_iterator<char>(is), {}};
  int ans;
  if constexpr (!part2) {
    ans = react(s);
  } else {
    ans = ranges::min(view::iota('a', 'z') | view::transform([&](char C) {
                        return react(s | view::filter([&](char c) { return tolower(c) != C; }));
                      }));
  }
  os << ans << '\n';
}

template void
Day<5>::solve<true>(std::istream &, std::ostream &);
template void
Day<5>::solve<false>(std::istream &, std::ostream &);
