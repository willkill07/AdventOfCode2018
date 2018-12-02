#ifndef UTIL_WILLIAM_KILLIAN_2018_ADVENT_HPP_
#define UTIL_WILLIAM_KILLIAN_2018_ADVENT_HPP_

#include <algorithm>
#include <iterator>
#include <optional>
#include <type_traits>
#include <vector>

template <typename Container, typename Fn>
auto
combinations(Container const& c, size_t k, Fn&& f) {
  using T = std::add_const_t<typename Container::value_type>;
  using R = decltype(f(std::declval<std::vector<std::reference_wrapper<T>>>()));
  std::vector<std::reference_wrapper<T>> res(std::begin(c), std::begin(c) + k);
  std::vector<bool> v(k, true);
  v.resize(std::size(c));
  do {
    for (size_t i{0}, j{0}; i < v.size(); ++i) {
      if (v[i]) {
        res[j++] = c[i];
      }
    }
    if (auto val = f(res); val) {
      return val;
    }
  } while (std::prev_permutation(std::begin(v), std::end(v)));
  return R{};
}

#endif
