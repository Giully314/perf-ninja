#include <vector>

// Assume those constants never change
constexpr int N = 1000000;
constexpr int minRandom = 0;
constexpr int maxRandom = 100;

// FIXME: this data structure can be reduced in size
// Solution(Giully): Change the order from the greater (in size) to the
// smallest. This reduce the padding and so the size of the structure.
// Also we can change the types, assuming the above constants, so it requires
// less space -> more data in cacheline -> less access to ram -> more speed.
struct S {
  float d;
  short l;
  short i : 8;
  short s : 7;
  bool b : 1;

  bool operator<(const S &s) const { return this->i < s.i; }
};

void init(std::vector<S> &arr);
S create_entry(int first_value, int second_value);
void solution(std::vector<S> &arr);
