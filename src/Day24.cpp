#include "Solution.hpp"

template <>
template <bool part2>
void
Day<24>::solve(std::istream &is, std::ostream &os) {
  is.good();
  os << std::endl;
}

template void Day<24>::solve<true>(std::istream&, std::ostream&);
template void Day<24>::solve<false>(std::istream&, std::ostream&);
