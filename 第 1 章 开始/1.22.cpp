#include <iostream>
#include "Sales_item.h"

int main(int argc, char const *argv[]) {
  Sales_item item, total;
  while (std::cin >> item) {
    total += item;
  }
  std::cout << "Total:" << total << std::endl;
  return 0;
}
