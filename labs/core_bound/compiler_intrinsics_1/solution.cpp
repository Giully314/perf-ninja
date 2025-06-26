
#include "solution.h"
#include <memory>
#include <immintrin.h>

void imageSmoothing(const InputVector &input, uint8_t radius,
                    OutputVector &output) {
  int pos = 0;
  int currentSum = 0;
  int size = static_cast<int>(input.size());

  // 1. left border - time spend in this loop can be ignored, no need to
  // optimize it
  for (int i = 0; i < std::min<int>(size, radius); ++i) {
    currentSum += input[i];
  }

  int limit = std::min(radius + 1, size - radius);
  for (pos = 0; pos < limit; ++pos) {
    currentSum += input[pos + radius];
    output[pos] = currentSum;
  }
  
  
  // The code for this solution is taken from the video. I solved the problem
  // on paper by recognizing the cumulative sum but i have zero experience 
  // using instrinsics and the docs from intel are barebone.
  
  // 2. main loop.
  limit = size - radius;
  const uint8_t* subtract_ptr = input.data() + pos - radius - 1;
  const uint8_t* add_ptr = input.data() + pos + radius;
  const uint16_t* output_ptr = output.data() + pos;
  __m128i current = _mm_set1_epi16(currentSum);

  int i = 0;

  // Process 8 element at time.
  for (; i + 7 < limit - pos; i += 8) {
    // First compute the difference from input vector.
    // Equivalen to the -= input[pos - radius - 1] + input[pos + radius]
    __m128i sub_u8 = _mm_loadu_si64(subtract_ptr + i);
    __m128i sub = _mm_cvtepu8_epi16(sub_u8);
    __m128i add_u8 = _mm_loadu_si64(add_ptr + i);
    __m128i add = _mm_cvtepu8_epi16(add_u8);

    __m128i diff = _mm_sub_epi16(add, sub);


    // Compute the prefix for 8 elements
    __m128i s = _mm_add_epi16(diff, _mm_slli_si128(diff, 2));
    s = _mm_add_epi16(s, _mm_slli_si128(s, 4));
    s = _mm_add_epi16(s, _mm_slli_si128(s, 8));

    // Store the result
    __m128i result = _mm_add_epi16(s, current);
    _mm_storeu_si128((__m128i*)(output_ptr + i), result);

    // broadcast current_sum for the next iteration
    currentSum = (uint16_t)_mm_extract_epi16(result, 7);
    current = _mm_set1_epi16(currentSum);
  }
  pos += i; 

  for (; pos < limit; ++pos) { 
    currentSum -= input[pos - radius - 1];
    currentSum += input[pos + radius];
    output[pos] = currentSum;
  }

  // 3. special case, executed only if size <= 2*radius + 1
  limit = std::min(radius + 1, size);
  for (; pos < limit; pos++) {
    output[pos] = currentSum;
  }

  // 4. right border - time spend in this loop can be ignored, no need to
  // optimize it
  for (; pos < size; ++pos) {
    currentSum -= input[pos - radius - 1];
    output[pos] = currentSum;
  }
}
