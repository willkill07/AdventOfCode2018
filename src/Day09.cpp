#include "Solution.hpp"

#include <iterator>
#include <range/v3/algorithm/max.hpp>
#include <vector>

template <typename T>
struct circular_list {

  struct node {
    node* prev;
    node* next;
    T data;
  };

  ~circular_list() {
    node* n = curr->next;
    while (n != curr) {
      delete std::exchange(n, n->next);
    }
    delete curr;
  }

  void insert(T data) {
    node* n = new node;
    n->data = data;
    if (curr == nullptr) {
      n->prev = n->next = n;
    } else {
      n->prev = curr->prev;
      n->next = curr;
      n->prev->next = n->next->prev = n;
    }
    curr = n;
  }

  T remove() {
    T data = curr->data;
    if (curr->next == curr) {
      delete std::exchange(curr, nullptr);
    } else {
      curr->prev->next = curr->next;
      curr->next->prev = curr->prev;
      delete std::exchange(curr, curr->next);
    }
    return data;
  }

  void next(int n = 1) {
    while (n--) curr = curr->next;
  }

  void prev(int n = 1) {
    while (n--) curr = curr->prev;
  }

  node* curr = nullptr;
};

template <>
template <bool part2>
void
Day<9>::solve(std::istream& is, std::ostream& os) {
  int players, marbles;
  std::string line{std::istream_iterator<char>(is), {}};
  sscanf(line.c_str(), "%d players; last marble is worth %d points", &players, &marbles);
  if constexpr (part2) {
    marbles *= 100;
  }
  std::vector<unsigned long long> p(players);

  circular_list<int> l;
  l.insert(0);
  for (int m = 1; m < marbles; ++m) {
    if (m % 23 == 0) {
      l.prev(7);
      p[m % players] += m + l.remove();
    } else {
      l.next(2);
      l.insert(m);
    }
  }
  os << ranges::max(p) << '\n';
}

template void
Day<9>::solve<true>(std::istream&, std::ostream&);
template void
Day<9>::solve<false>(std::istream&, std::ostream&);
