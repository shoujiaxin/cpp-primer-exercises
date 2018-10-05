#include <iostream>
#include <string>
#include "Sales_data.h"

int main(int argc, char const *argv[]) {
  Sales_data data;
  while (std::cin >> data.bookNo >> data.units_sold >> data.price) {
    data.revenue = data.units_sold * data.price;
    std::cout << data.bookNo << " " << data.units_sold << " " << data.revenue
              << " " << data.price << std::endl;
  }
  return 0;
}
