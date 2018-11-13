#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
 public:
  Employee() : id(uniqueId++) {}
  Employee(const std::string& str) : name(str), id(uniqueId++) {}
  Employee(const Employee&) = delete;
  Employee& operator=(const Employee&) = delete;

 private:
  std::string name;
  int id;
  static int uniqueId;
};

int Employee::uniqueId = 0;

#endif
