#include "Solution.hpp"

#include <map>
#include <range/v3/all.hpp>
#include <range/v3/getlines.hpp>
#include <set>

void
stuff() {
}

// from collections import defaultdict, deque
// # Edges
// E = defaultdict(list)
// # In-degree
// D = defaultdict(int)
// for line in open('7.in'):
//     words = line.split()
//     x = words[1]
//     y = words[7]
//     E[x].append(y)
//     D[y] += 1
//
// for k in E:
//     E[k] = sorted(E[k])
//
// # time
// t = 0
// # Events
// EV = []
// # Work queue
// Q = []
// def add_task(x):
//     Q.append(x)
// def start_work():
//     global Q
//     while len(EV) < 5 and Q:
//         x = min(Q)
//         Q = [y for y in Q if y!=x]
//         print 'Starting {} at {}'.format(x, t)
//         EV.append((t+61+ord(x)-ord('A'), x))
//
// for k in E:
//     if D[k] == 0:
//         add_task(k)
// start_work()
//
// while EV or Q:
//     t, x = min(EV)
//     print t,x
//     EV = [y for y in EV if y!=(t,x)]
//     for y in E[x]:
//         D[y] -= 1
//         if D[y] == 0:
//             add_task(y)
//     start_work()
//
// print t
//
//
//
// #ans = ""
// #while Q:
// #    x = sorted(Q)[0]
// #    Q = [y for y in Q if y!=x]
// #    ans += x
// #    for y in E[x]:
// #        D[y] -= 1
// #        if D[y] == 0:
// #            Q.append(y)
// #print ans
// #

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
