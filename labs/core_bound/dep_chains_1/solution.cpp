#include "solution.hpp"
#include <array>
#include <iostream>
#include <print>

unsigned getSumOfDigits(unsigned n) {
  unsigned sum = 0;
  while (n != 0) {
    sum = sum + n % 10;
    n = n / 10;
  }
  return sum;
}

// Task: lookup all the values from l2 in l1.
// For every found value, find the sum of its digits.
// Return the sum of all digits in every found number.
// Both lists have no duplicates and elements placed in *random* order.
// Do NOT sort any of the lists. Do NOT store elements in a hash_map/sets.

// Hint: Traversing a linked list is a long data dependency chain:
//       to get the node N+1 you need to retrieve the node N first.
//       Think how you can execute multiple dependency chains in parallel.
unsigned solution(List *l1, List *l2) {
  unsigned retVal = 0;
  constexpr auto size = 4;
  unsigned vals[size] = {0};
  List *head2 = l2;
  // O(N^2) algorithm:
  while (l1) {
    // std::println("loading values");
    for (int i = 0; i < size; ++i) {
      if (l1) {
        vals[i] = l1->value;
      } else {
        break;
      }
      l1 = l1->next;
    }

    // std::println("checking values");
    l2 = head2;
    while (l2) {
      for (int i = 0; i < size; ++i) {
        if (l2->value == vals[i]) {
          retVal += getSumOfDigits(l2->value);
          vals[i] = 0;
        }
      }
      
      if (vals[0] == 0 && vals[1] == 0 && vals[2] == 0 && vals[3] == 0) {
        break;
      }
      l2 = l2->next;
    }
  }

  return retVal;
}
