#include <iostream>

unsigned fact(unsigned val) {
  unsigned result = 1;
  while (val > 1) {
    result *= val;
    --val;
  }
  return result;
}

int main(int argc, char const *argv[]) {
  std::cout << fact(5) << std::endl;
  return 0;
}
