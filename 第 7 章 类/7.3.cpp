#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  std::string bookName;
  unsigned int units_sold = 0;
  double price = 0.0;    // 单价
  double revenue = 0.0;  // 总收入

  Sales_data& combine(const Sales_data& rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }

  std::string isbn() const { return bookNo; }
};

int main(int argc, char const* argv[]) {
  Sales_data total;
  if (std::cin >> total.bookNo >> total.units_sold >> total.price) {
    total.revenue = total.units_sold * total.price;
    Sales_data trans;
    while (std::cin >> trans.bookNo >> trans.units_sold >> trans.price) {
      if (total.isbn() == trans.isbn()) {
        trans.revenue = trans.units_sold * trans.price;
        total.combine(trans);
      } else {
        std::cout << total.isbn() << " " << total.units_sold << " "
                  << total.revenue << " " << total.revenue / total.units_sold
                  << std::endl;
        total = trans;
      }
    }
    std::cout << total.isbn() << " " << total.units_sold << " " << total.revenue
              << " " << total.revenue / total.units_sold << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
    return -1;
  }
  return 0;
}
