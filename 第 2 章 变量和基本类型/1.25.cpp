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
  Sales_data total;
  if (std::cin >> total.bookNo >> total.num >> total.price) {
    total.revenue = total.num * total.price;
    Sales_data trans;
    while (std::cin >> trans.bookNo >> trans.num >> trans.price) {
      trans.revenue = trans.num * trans.price;
      if (total.bookNo == trans.bookNo) {
        total.num += trans.num;
        total.revenue += trans.revenue;
      } else {
        total.price = total.revenue / total.num;
        std::cout << total.bookNo << " " << total.num << " " << total.revenue
                  << " " << total.price << std::endl;
        total.bookNo = trans.bookNo;
        total.num = trans.num;
        total.price = trans.price;
        total.revenue = trans.revenue;
      }
    }
    total.price = total.revenue / total.num;
    std::cout << total.bookNo << " " << total.num << " " << total.revenue << " "
              << total.price << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
  return 0;
}
