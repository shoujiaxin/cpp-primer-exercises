#include <iostream>
#include <string>
#include "Sales_data.h"

int main(int argc, char const *argv[]) {
  Sales_data data1, data2;
  std::cin >> data1.bookNo >> data1.num >> data1.price;
  std::cin >> data2.bookNo >> data2.num >> data2.price;
  data1.revenue = data1.num * data1.price;
  data2.revenue = data2.num * data2.price;

  if (data1.bookNo == data2.bookNo) {
    unsigned int totalNum = data1.num + data2.num;
    double totalRevenue = data1.revenue + data2.revenue;
    double ave = totalRevenue / totalNum;
    std::cout << data1.bookNo << " " << totalNum << " "
              << data1.revenue + data2.revenue << " " << ave << std::endl;
  }
  return 0;
}
