#include "Solution.hpp"

#include <iterator>
#include <vector>

#include <range/v3/numeric.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/filter.hpp>

namespace view = ranges::view;

struct node {
  std::vector<unsigned long long> meta;
  std::vector<node> children;
};

node read(std::istream_iterator<int>& i) {
  node n;
  int c = *i++, m = *i++;
  while (c--) {
    n.children.push_back(read(i));
  }
  while (m--) {
    n.meta.push_back(*i++);
  }
  return n;
}

int total(const node& node) {
  return ranges::accumulate(node.children | view::transform(total), 0) + ranges::accumulate(node.meta, 0);
}

int value(const node& node) {
  if (node.children.empty()) {
    return total(node);
  }
  return ranges::accumulate(node.meta
                            | view::filter([&](size_t d) { return d > 0 && d <= node.children.size(); })
                            | view::transform([&](size_t d) { return value(node.children[d - 1]); }),
                            0);
}

template <>
template <bool part2>
void
Day<8>::solve(std::istream& is, std::ostream& os) {

  std::istream_iterator<int> iter{is};
  if constexpr(part2) {
    os << value(read(iter)) << '\n';
  } else {
    os << total(read(iter)) << '\n';
  }
}

template void
Day<8>::solve<true>(std::istream&, std::ostream&);
template void
Day<8>::solve<false>(std::istream&, std::ostream&);
