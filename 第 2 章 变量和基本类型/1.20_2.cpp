#include <iostream>
#include <string>
#include "Sales_data.h"

int main(int argc, char const *argv[]) {
  Sales_data data;
  while (std::cin >> data.bookNo >> data.num >> data.price) {
    data.revenue = data.num * data.price;
    std::cout << data.bookNo << " " << data.num << " " << data.revenue << " "
              << data.price << std::endl;
  }
  return 0;
}
