#include <iostream>
#include <string>
#include "Sales_data.h"

int main(int argc, char const *argv[]) {
  Sales_data data, total;
  while (std::cin >> data.bookNo >> data.units_sold >> data.price) {
    data.revenue = data.units_sold * data.price;
    total.bookNo = data.bookNo;
    total.units_sold += data.units_sold;
    total.revenue += data.revenue;
    total.price = total.revenue / total.units_sold;
  }
  std::cout << "Total: " << total.units_sold << " " << total.revenue << " "
            << total.price << std::endl;
  return 0;
}
