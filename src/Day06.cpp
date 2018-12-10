#include "Solution.hpp"

#include <limits>
#include <iterator>
#include <set>
#include <vector>

#include <range/v3/algorithm/min.hpp>
#include <range/v3/view/indices.hpp>
#include <range/v3/view/transform.hpp>
#include <range/v3/view/zip.hpp>

namespace view = ranges::view;

struct Point {
  int x, y;
  int
  operator^(Point const &p) const {
    return std::abs(x - p.x) + std::abs(y - p.y);
  }
};

std::istream &
operator>>(std::istream &is, Point &p) {
  is >> p.x;
  is.ignore();
  is >> p.y;
  return is;
}

template <>
template <bool part2>
void
Day<6>::solve(std::istream &is, std::ostream &os) {
  std::vector<Point> points(std::istream_iterator<Point>(is), {});

  int minX, minY, maxX, maxY;
  minX = minY = std::numeric_limits<int>::max();
  maxX = maxY = std::numeric_limits<int>::min();
  for (auto const [x, y] : points) {
    minX = std::min(minX, x);
    minY = std::min(minY, y);
    maxX = std::max(maxX, x);
    maxY = std::max(maxY, y);
  }

  if constexpr (!part2) {
    const size_t INVALID = points.size();
    const int MAX = std::numeric_limits<int>::max();

    std::vector<int> num_claimed(points.size() + 1, 0);
    std::set<size_t> invalid_points;

    auto min_index = [&](int x, int y) {
      size_t minIdx = INVALID;
      int dist = MAX;
      for (auto const &[i, p] : view::zip(view::indices, points)) {
        if (int d = Point{x, y} ^ p; dist > d) {
          std::tie(minIdx, dist) = std::tuple(i, d);
        } else if (dist == d) {
          minIdx = INVALID;
        }
      }
      return std::pair(minIdx, dist);
    };

    auto Xs = view::closed_iota(minX, maxX);
    auto Ys = view::closed_iota(minY, maxY);

    for (int x : Xs) {
      invalid_points.insert(min_index(x, minY).first);
      invalid_points.insert(min_index(x, maxY).first);
    }
    for (int y : Ys) {
      invalid_points.insert(min_index(minX, y).first);
      invalid_points.insert(min_index(maxX, y).first);
    }

    for (auto x : Xs) {
      for (auto y : Ys) {
        auto [idx, _] = ranges::min(view::zip(view::indices, points), std::less<>{}, [&](auto const &pair) {
          auto [i, p] = pair;
          return p ^ Point { x, y };
        });
        if (invalid_points.count(idx) == 0) {
          ++num_claimed[idx];
        }
      }
    }
    os << ranges::max(num_claimed) << '\n';
    return;
  } else {
    constexpr size_t CUTOFF(10'000);
    const size_t PADDING{CUTOFF / points.size() + 1};
    auto Xs = view::closed_iota(minX - PADDING, maxX + PADDING);
    auto Ys = view::closed_iota(minY - PADDING, maxY + PADDING);
    size_t area{0};
    for (int x : Xs) {
      for (int y : Ys) {
        size_t dist{0};
        Point loc{x, y};
        for (auto const &p : points) {
          dist += loc ^ p;
          if (dist >= CUTOFF) {
            break;
          }
        }
        if (dist < CUTOFF) {
          ++area;
        }
      }
    }
    os << area << '\n';
  }
}

template void
Day<6>::solve<true>(std::istream &, std::ostream &);
template void
Day<6>::solve<false>(std::istream &, std::ostream &);
