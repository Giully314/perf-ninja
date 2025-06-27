#include "solution.hpp"

#define SOLUTION

#ifdef SOLUTION

uint16_t checksum(const Blob &blob) {
  uint32_t acc = 0;
  for (auto value : blob) {
    acc += value;
  }

  while (acc >> 16) {
    acc = (acc & 0xffff) + (acc >> 16);
  }

  return static_cast<uint16_t>(acc);
}

#else

uint16_t checksum(const Blob &blob) {
  uint16_t acc = 0;
  for (auto value : blob) {
    acc += value;
    acc += acc < value; // add carry
  }
  return acc;
}

#endif 