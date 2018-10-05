#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Sales_data {
  std::string bookNo;
  std::string bookName;
  unsigned int units_sold = 0;
  double price = 0.0;    // 单价
  double revenue = 0.0;  // 总收入
};

int main(int argc, char const *argv[]) {
  Sales_data currData, data;
  if (cin >> currData.bookNo >> currData.units_sold >> data.price) {
    int cnt = 1;
    while (cin >> data.bookNo >> data.units_sold >> data.price) {
      if (data.bookNo == currData.bookNo) {
        cnt++;
      } else {
        cout << "ISBN: " << currData.bookNo << ", Num: " << cnt << endl;
        currData.bookNo = data.bookNo;
        currData.units_sold = data.units_sold;
        currData.price = data.price;
        cnt = 1;
      }
    }
    cout << "ISBN: " << currData.bookNo << ", Num: " << cnt << endl;
  }
  return 0;
}
