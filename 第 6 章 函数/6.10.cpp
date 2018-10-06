#include <iostream>

void swap(int *val1, int *val2) {
  int tmp = *val1;
  *val1 = *val2;
  *val2 = tmp;
}

int main(int argc, char const *argv[]) {
  int a = 1, b = 2;
  std::cout << "Before: a = " << a << ", b = " << b << std::endl;
  swap(&a, &b);
  std::cout << "After: a = " << a << ", b = " << b << std::endl;
  return 0;
}
