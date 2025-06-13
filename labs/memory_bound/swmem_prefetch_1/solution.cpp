#include "solution.hpp"

static int getSumOfDigits(int n) {
  int sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}

int solution(const hash_map_t *hash_map, const std::vector<int> &lookups) {
  // First solution tried.
  // const auto n = hash_map->N_Buckets;
  // auto prevalue = lookups[0];
  // auto previdx = prevalue % n; 
  // auto value = 0;
  // auto nextidx = 0;
  // for (int i = 1; i < lookups.size()-1; ++i) {
  //   value = lookups[i+1];  
  //   nextidx = value % n;
  //   __builtin_prefetch(hash_map->m_vector.data() + nextidx);
  //   if (hash_map->m_vector[previdx] != hash_map->UNUSED) {
  //     result += getSumOfDigits(prevalue);
  //   }
  //   previdx = nextidx;
  //   prevalue = value;
  // }
  
  // if (lookups.size() != 1 && hash_map->find(lookups.back())) {
  //   result += getSumOfDigits(lookups.back());
  // }

  // We can issue memory prefetch ahead of time by starting loading future values into the cache.
  // This works only if lookups has a lot of entries.
  constexpr auto ahead = 128;

  int result = 0; 
  
  for (int i = 0; i < lookups.size() - ahead; ++i) {
    if (hash_map->find(lookups[i])) {
      result += getSumOfDigits(lookups[i]);
    }
    hash_map->prefetch(lookups[i + ahead]);
  }

  for (int i = lookups.size() - ahead; i < lookups.size(); ++i) {
    if (hash_map->find(lookups[i])) {
      result += getSumOfDigits(lookups[i]);
    }
  }

  // Original.
  // for (const auto val : lookups) {
  //   if (hash_map->find(val)) {
  //     result += getSumOfDigits(val);
  //   }
  // }

  return result;
}
