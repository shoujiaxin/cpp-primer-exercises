#include <iostream>

void reset(int &val) { val = 0; }

int main(int argc, char const *argv[]) {
  int n = 4;
  std::cout << "Before: n = " << n << std::endl;
  reset(n);
  std::cout << "After: n = " << n << std::endl;
  return 0;
}
