#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

struct Sales_data {
  Sales_data() = default;
  Sales_data(const std::string &str) : bookNo(str) {}
  Sales_data(const std::string &str, unsigned n, double p)
      : bookNo(str), units_sold(n), price(p), revenue(n * p) {}
  Sales_data(std::istream &is) {
    is >> this->bookNo >> this->units_sold >> this->price;
    this->revenue = this->units_sold * this->price;
  }

  std::string bookNo;
  std::string bookName;
  unsigned int units_sold = 0;
  double price = 0.0;    // 单价
  double revenue = 0.0;  // 总收入

  Sales_data &combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }

  std::string isbn() const { return bookNo; }

  double avg_price() const;
};

double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

Sales_data add(const Sales_data &data1, const Sales_data &data2) {
  Sales_data sum = data1;
  return sum.combine(data2);
}

std::istream &read(std::istream &is, Sales_data &data) {
  is >> data.bookNo >> data.units_sold >> data.price;
  data.revenue = data.units_sold * data.price;
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &data) {
  os << data.isbn() << " " << data.units_sold << " " << data.revenue << " "
     << data.avg_price();
  return os;
}

#endif
