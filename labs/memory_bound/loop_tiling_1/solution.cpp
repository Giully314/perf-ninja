#include "solution.hpp"
#include <algorithm>

bool solution(MatrixOfDoubles &in, MatrixOfDoubles &out) {
  int size = in.size();
  int ii;
  int jj;
  constexpr auto inc = 16;
  for (ii = 0; ii < size; ii += inc) {
    for (jj = 0; jj < size; jj += inc) {

      for (int i = ii; i < std::min(ii + inc, size); i++) {
        for (int j = jj; j < std::min(jj + inc, size); j++) {
          out[i][j] = in[j][i];
        }
      }

    }
  } 
  return out[0][size - 1];
}
