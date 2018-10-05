#include <iostream>
#include <string>
#include "Sales_data.h"

int main(int argc, char const *argv[]) {
  Sales_data data, total;
  while (std::cin >> data.bookNo >> data.num >> data.price) {
    data.revenue = data.num * data.price;
    total.bookNo = data.bookNo;
    total.num += data.num;
    total.revenue += data.revenue;
    total.price = total.revenue / total.num;
  }
  std::cout << "Total: " << total.num << " " << total.revenue << " "
            << total.price << std::endl;
  return 0;
}
