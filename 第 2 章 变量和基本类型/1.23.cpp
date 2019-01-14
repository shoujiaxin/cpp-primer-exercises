#include <iostream>
#include <string>

struct Sales_data {
  std::string bookNo;
  std::string bookName;
  unsigned int units_sold = 0;
  double revenue = 0.0;  // 总收入
};

int main(int argc, char const *argv[]) {
  Sales_data currData, data;
  double price = 0;
  if (std::cin >> currData.bookNo >> currData.units_sold >> price) {
    currData.revenue = currData.units_sold * price;
    int cnt = 1;
    while (std::cin >> data.bookNo >> data.units_sold >> price) {
      data.revenue = data.units_sold * price;
      if (data.bookNo == currData.bookNo) {
        cnt++;
      } else {
        std::cout << "bookNo: " << currData.bookNo << ", Num: " << cnt
                  << std::endl;
        currData.bookNo = data.bookNo;
        currData.units_sold = data.units_sold;
        currData.revenue = data.revenue;
        cnt = 1;
      }
    }
    std::cout << "bookNo: " << currData.bookNo << ", Num: " << cnt << std::endl;
  }
  return 0;
}
