#include "Solution.hpp"

#include <unordered_map>
#include <vector>

#include <range/v3/algorithm.hpp>
#include <range/v3/getlines.hpp>
#include <range/v3/numeric.hpp>
#include <range/v3/view/slice.hpp>

namespace view = ranges::view;

template <>
template <bool part2>
void
Day<4>::solve(std::istream& is, std::ostream& os) {
  std::vector<std::string> events(ranges::getlines(is));
  ranges::sort(events);

  std::unordered_map<int, std::array<int, 60>> guards;
  {
    int id {0}, start {0}, stop {0};
    char c;
    for (std::string const& s : events) {
      if (sscanf(s.c_str() + 15, "%d] %c", &stop, &c) == 2 && c == 'w') {
        for (auto& t : guards[id] | view::slice(start, stop)) {
          ++t;
        }
      } else if (sscanf(s.c_str() + 15, "%d] %c", &start, &c) == 2 && c == 'f') {
      } else if (sscanf(s.c_str() + 19, "Guard #%d", &id) == 1) {
      }
    }
  }
  auto max = [](const auto& l) {
    return ranges::distance(ranges::begin(l), ranges::max_element(l));
  };
  auto map = [&](auto const& pair) {
    if constexpr (auto& [_, l] = pair; part2) {
      return ranges::max(l);
    } else {
      return ranges::accumulate(l, 0);
    }
  };
  const auto& [id, data] = *ranges::max_element(guards, std::less<> {}, map);
  const auto& minute = max(data);
  os << id * minute << std::endl;
}

template void
Day<4>::solve<true>(std::istream&, std::ostream&);
template void
Day<4>::solve<false>(std::istream&, std::ostream&);
