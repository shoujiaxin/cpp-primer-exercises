#include <iostream>
#include <string>
#include "Sales_data.h"

int main(int argc, char const *argv[]) {
  Sales_data total;
  if (std::cin >> total.bookNo >> total.units_sold >> total.price) {
    total.revenue = total.units_sold * total.price;
    Sales_data trans;
    while (std::cin >> trans.bookNo >> trans.units_sold >> trans.price) {
      trans.revenue = trans.units_sold * trans.price;
      if (total.bookNo == trans.bookNo) {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        total.price = total.revenue / total.units_sold;
        std::cout << total.bookNo << " " << total.units_sold << " "
                  << total.revenue << " " << total.price << std::endl;
        total.bookNo = trans.bookNo;
        total.units_sold = trans.units_sold;
        total.price = trans.price;
        total.revenue = trans.revenue;
      }
    }
    total.price = total.revenue / total.units_sold;
    std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue
              << " " << total.price << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
  return 0;
}
