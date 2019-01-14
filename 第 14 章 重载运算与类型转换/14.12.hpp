#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee {
  friend std::istream& operator>>(std::istream&, Employee&);
  friend std::ostream& operator<<(std::ostream&, const Employee&);

 public:
  Employee() = default;
  Employee(int i, std::string n, int ag = 0, std::string p = "",
           std::string ad = "")
      : id(i), name(n), age(ag), phone(p), address(ad) {}

 private:
  int id;
  std::string name;
  int age;
  std::string phone;
  std::string address;
};

std::istream& operator>>(std::istream& is, Employee& e) {
  is >> e.id >> e.name >> e.age >> e.phone >> e.address;
  if (!is) {
    e = Employee();
  }
  return is;
}

std::ostream& operator<<(std::ostream& os, const Employee& e) {
  os << e.id << " " << e.name << " " << e.age << " " << e.phone << " "
     << e.address;
  return os;
}

#endif
