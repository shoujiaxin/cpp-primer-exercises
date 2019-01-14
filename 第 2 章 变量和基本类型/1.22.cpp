#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  std::string bookName;
  unsigned int units_sold = 0;
  double revenue = 0.0;  // 总收入
};

int main(int argc, char const *argv[]) {
  Sales_data data, total;
  double price = 0;
  while (std::cin >> data.bookNo >> data.units_sold >> price) {
    data.revenue = data.units_sold * price;
    total.bookNo = data.bookNo;
    total.units_sold += data.units_sold;
    total.revenue += data.revenue;
  }
  std::cout << "Total: " << total.units_sold << " " << total.revenue << " "
            << total.revenue / total.units_sold << std::endl;
  return 0;
}
