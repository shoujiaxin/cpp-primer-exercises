#include <iostream>
#include "Sales_item.h"

int main(int argc, char const *argv[]) {
  Sales_item item;
  while (std::cin >> item) {
    std::cout << item << std::endl;
  }
  return 0;
}
