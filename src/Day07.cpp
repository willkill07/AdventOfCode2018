#include "Solution.hpp"

#include <map>
#include <set>
#include <vector>

#include <range/v3/algorithm/max.hpp>
#include <range/v3/view/filter.hpp>
#include <range/v3/view/map.hpp>
#include <range/v3/getlines.hpp>

template <>
template <bool part2>
void
Day<7>::solve(std::istream &is, std::ostream &os) {
  std::map<char, std::set<char>> adj;
  std::map<char, int> deg;
  for (auto const &s : ranges::getlines(is)) {
    char src, dst;
    sscanf(s.c_str(), "Step %c must be finished before step %c can begin.", &src, &dst);
    adj[src].insert(dst);
    ++deg[dst];
  }

  std::set<char> q(adj | ranges::view::keys | ranges::view::filter([&deg](char c) { return deg.count(c) == 0; }));
  if constexpr (!part2) {
    while (!q.empty()) {
      char v = *q.begin();
      os << v;
      q.erase(v);
      for (char c : adj[v]) {
        if (--deg[c] == 0) {
          q.insert(c);
        }
      }
    }
  } else {
    int simTime = 0;
    std::vector<std::pair<char,int>> workers(5);

    while (true) {
      for (auto & [wID, wTime] : workers) {
        if (wID != 0) {
          if (--wTime == 0) {
            for (char c : adj[wID]) {
              if (--deg[c] == 0) {
                q.insert(c);
              }
            }
            wID = wTime = 0;
          }
        }
      }
      for (auto & [wID, wTime] : workers) {
        if (wID == 0 && !q.empty()) {
          wID = *q.begin();
          q.erase(wID);
          wTime = wID - 'A' + 61;
        }
      }
      if (q.empty() && ranges::max(workers | ranges::view::values) == 0)
        break;
      ++simTime;
    }
    os << simTime;
  }
  os << '\n';
}

template void
Day<7>::solve<true>(std::istream &, std::ostream &);
template void
Day<7>::solve<false>(std::istream &, std::ostream &);
