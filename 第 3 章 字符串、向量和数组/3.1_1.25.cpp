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
  Sales_data total;
  if (cin >> total.bookNo >> total.units_sold >> total.price) {
    total.revenue = total.units_sold * total.price;
    Sales_data trans;
    while (cin >> trans.bookNo >> trans.units_sold >> trans.price) {
      trans.revenue = trans.units_sold * trans.price;
      if (total.bookNo == trans.bookNo) {
        total.units_sold += trans.units_sold;
        total.revenue += trans.revenue;
      } else {
        total.price = total.revenue / total.units_sold;
        cout << total.bookNo << " " << total.units_sold << " " << total.revenue
             << " " << total.price << endl;
        total.bookNo = trans.bookNo;
        total.units_sold = trans.units_sold;
        total.price = trans.price;
        total.revenue = trans.revenue;
      }
    }
    total.price = total.revenue / total.units_sold;
    cout << total.bookNo << " " << total.units_sold << " " << total.revenue
         << " " << total.price << endl;
  } else {
    cerr << "No data?!" << endl;
    return -1;
  }
  return 0;
}
