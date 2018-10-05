#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  std::string bookName;
  unsigned int units_sold = 0;
  double price = 0.0;    // 单价
  double revenue = 0.0;  // 总收入
};

int main(int argc, char const *argv[]) {
  Sales_data data;
  while (std::cin >> data.bookNo >> data.num >> data.price) {
    data.revenue = data.num * data.price;
    std::cout << data.bookNo << " " << data.num << " " << data.revenue << " "
              << data.price << std::endl;
  }
  return 0;
}
