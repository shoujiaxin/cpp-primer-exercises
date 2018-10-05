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
  Sales_data currData, data;
  if (std::cin >> currData.bookNo >> currData.num >> data.price) {
    int cnt = 1;
    while (std::cin >> data.bookNo >> data.num >> data.price) {
      if (data.bookNo == currData.bookNo) {
        cnt++;
      } else {
        std::cout << "bookNo: " << currData.bookNo << ", Num: " << cnt
                  << std::endl;
        currData.bookNo = data.bookNo;
        currData.num = data.num;
        currData.price = data.price;
        cnt = 1;
      }
    }
    std::cout << "bookNo: " << currData.bookNo << ", Num: " << cnt << std::endl;
  }
  return 0;
}
