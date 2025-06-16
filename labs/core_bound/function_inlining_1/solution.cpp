
#include "solution.h"
#include <algorithm>
#include <stdlib.h>

// static int compare(const void *lhs, const void *rhs) {
//   auto &a = *reinterpret_cast<const S*>(lhs);
//   auto &b = *reinterpret_cast<const S *>(rhs);

//   if (a.key1 < b.key1)
//     return -1;

//   if (a.key1 > b.key1)
//     return 1;

//   if (a.key2 < b.key2)
//     return -1;

//   if (a.key2 > b.key2)
//     return 1;

//   return 0;
// }



[[gnu::always_inline]]
static inline bool compare(const S& a, const S& b) {
  if (a.key1 < b.key1)
    return true;

  if (a.key1 > b.key1)
    return false;

  if (a.key2 < b.key2)
    return true;

  if (a.key2 > b.key2)
    return false;

  return true;
}


struct Comparator {
  [[gnu::always_inline]]
  inline bool operator()(const S& a, const S& b) {
  if (a.key1 < b.key1)
    return true;

  if (a.key1 > b.key1)
    return false;

  if (a.key2 < b.key2)
    return true;

  if (a.key2 > b.key2)
    return false;

  return true;
} 
};

void solution(std::array<S, N> &arr) {
  // qsort(arr.data(), arr.size(), sizeof(S), compare);
  std::sort(arr.begin(), arr.end(), Comparator{});
}
