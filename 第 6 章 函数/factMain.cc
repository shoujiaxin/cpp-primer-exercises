#include <iostream>
#include "Chapter6.h"

int main(int argc, char const *argv[]) {
  unsigned v;
  std::cout << "Please input a number: ";
  std::cin >> v;
  std::cout << v << "! is " << fact(v) << std::endl;
  return 0;
}
