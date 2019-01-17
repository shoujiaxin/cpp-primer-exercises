#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

class Employee {
  friend std::istream& operator>>(std::istream&, Employee&);
  friend std::ostream& operator<<(std::ostream&, const Employee&);
  friend bool operator==(const Employee&, const Employee&);
  friend bool operator!=(const Employee&, const Employee&);
  friend bool operator<(const Employee&, const Employee&);

 public:
  Employee() = default;
  Employee(int i, std::string n, int ag = 0, std::string p = "",
           std::string ad = "")
      : id(i), name(n), age(ag), phone(p), address(ad) {}
  Employee& operator=(const Employee&);      // 拷贝赋值运算符
  Employee& operator=(Employee&&) noexcept;  // 移动赋值运算符

 private:
  int id;
  std::string name;
  int age;
  std::string phone;
  std::string address;
};

Employee& Employee::operator=(const Employee& rhs) {
  id = rhs.id;
  name = rhs.name;
  age = rhs.age;
  phone = rhs.phone;
  address = rhs.address;
  return *this;
}

Employee& Employee::operator=(Employee&& rhs) noexcept {
  if (this != &rhs) {
    id = rhs.id;
    name = rhs.name;
    age = rhs.age;
    phone = rhs.phone;
    address = rhs.address;
  }
  return *this;
}

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

bool operator==(const Employee& lhs, const Employee& rhs) {
  return lhs.id == rhs.id && lhs.name == rhs.name && lhs.age == rhs.age &&
         lhs.phone == rhs.phone && lhs.address == rhs.address;
}

bool operator!=(const Employee& lhs, const Employee& rhs) {
  return !(lhs == rhs);
}

bool operator<(const Employee& lhs, const Employee& rhs) {
  return lhs.id < rhs.id && lhs.name < rhs.name;
}

#endif
