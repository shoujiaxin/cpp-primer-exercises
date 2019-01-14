#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  std::string bookName;
  unsigned int units_sold = 0;
  double revenue = 0.0;  // 总收入
};

int main(int argc, char const* argv[]) {
  Sales_data total;
  double price = 0;
  if (std::cin >> total.bookNo >> total.units_sold >> price) {
    total.revenue = total.units_sold * price;
    Sales_data trans;
    while (std::cin >> trans.bookNo >> trans.units_sold >> price) {
      if (total.bookNo == trans.bookNo) {
        trans.revenue = trans.units_sold * price;
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        std::cout << total.bookNo << " " << total.units_sold << " "
                  << total.revenue << " " << total.revenue / total.units_sold
                  << std::endl;
        total = trans;
      }
    }
    std::cout << total.bookNo << " " << total.units_sold << " " << total.revenue
              << " " << total.revenue / total.units_sold << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
  return 0;
}
