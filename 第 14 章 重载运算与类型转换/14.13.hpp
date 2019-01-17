#ifndef SALES_DATA_H
#define SALES_DATA_H

#include <iostream>
#include <string>

struct Sales_data {
  friend Sales_data add(const Sales_data &, const Sales_data &);
  friend std::istream &read(std::istream &, Sales_data &);
  friend std::istream &operator>>(std::istream &, Sales_data &);
  friend std::ostream &print(std::ostream &, const Sales_data &);
  friend std::ostream &operator<<(std::ostream &, const Sales_data &);
  friend Sales_data operator+(const Sales_data &, const Sales_data &);
  friend Sales_data operator-(const Sales_data &, const Sales_data &);

 public:
  Sales_data() = default;
  Sales_data(const std::string &s, unsigned n, double p)
      : bookNo(s), units_sold(n), revenue(p * n) {}
  Sales_data(const std::string &s) : bookNo(s) {}
  Sales_data(std::istream &);
  std::string isbn() const { return bookNo; }
  Sales_data &combine(const Sales_data &rhs) {
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
  }
  Sales_data &operator+=(const Sales_data &);

 private:
  std::string bookNo;
  std::string bookName;
  unsigned int units_sold = 0;
  double revenue = 0.0;  // 总收入
  double avg_price() const;
};

inline double Sales_data::avg_price() const {
  return units_sold ? revenue / units_sold : 0;
}

Sales_data add(const Sales_data &data1, const Sales_data &data2) {
  Sales_data sum = data1;
  return sum.combine(data2);
}

std::istream &read(std::istream &is, Sales_data &data) {
  double price = 0;
  is >> data.bookNo >> data.units_sold >> price;
  data.revenue = data.units_sold * price;
  return is;
}

std::istream &operator>>(std::istream &is, Sales_data &data) {
  double price = 0;
  is >> data.bookNo >> data.units_sold >> price;
  if (is) {
    data.revenue = data.units_sold * price;
  } else {
    data = Sales_data();
  }
  return is;
}

std::ostream &print(std::ostream &os, const Sales_data &data) {
  os << data.isbn() << " " << data.units_sold << " " << data.revenue << " "
     << data.avg_price();
  return os;
}

std::ostream &operator<<(std::ostream &os, const Sales_data &data) {
  os << data.isbn() << " " << data.units_sold << " " << data.revenue << " "
     << data.avg_price();
  return os;
}

Sales_data::Sales_data(std::istream &is) { read(is, *this); }

Sales_data &Sales_data::operator+=(const Sales_data &rhs) {
  units_sold += rhs.units_sold;
  revenue += rhs.revenue;
  return *this;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data sum = lhs;
  sum += rhs;
  return sum;
}

Sales_data operator-(const Sales_data &lhs, const Sales_data &rhs) {
  Sales_data data = lhs;
  data.units_sold -= rhs.units_sold;
  data.revenue -= rhs.revenue;
  return data;
}

#endif
