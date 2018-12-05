#include "Solution.hpp"

#include <iterator>
#include <vector>

#include <range/v3/algorithm/min.hpp>
#include <range/v3/view/indices.hpp>
#include <range/v3/view/remove_if.hpp>
#include <range/v3/view/repeat.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/zip_with.hpp>

int
reaction(std::string s) {
  int size = s.size() - 1;
  auto i = std::next(std::begin(s));
  for (auto j = std::next(i); j != std::end(s); ++j) {
    if ((*i ^ *j) == 32) {
      --i, size -= 2;
    } else {
      std::iter_swap(++i, j);
    }
  }
  return size;
}

template <>
template <bool part2>
void
Day<5>::solve(std::istream &is, std::ostream &os) {
  std::string s {std::istream_iterator<char>(is), {}};
  s.insert(std::begin(s), '*');
  int ans;
  if constexpr (!part2) {
    ans = reaction(s);
  } else {
    using namespace ranges::view;
    auto strip = [](std::string const &s, char C) {
      return remove_if(s, [=](char c) { return ::tolower(c) == C; });
    };
    ans = ranges::min(zip_with(strip, repeat(s), closed_iota('a', 'z')) | transform(reaction));
  }
  os << ans << '\n';
}

template void
Day<5>::solve<true>(std::istream &, std::ostream &);
template void
Day<5>::solve<false>(std::istream &, std::ostream &);
