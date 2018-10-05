#include <iostream>
#include <string>
#include "Sales_data.h"

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
