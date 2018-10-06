#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
  friend std::istream& read(std::istream& is, Person& p);

 private:
  Person(const std::string& n, const std::string& a) : name(n), address(a) {}
  std::string Name() const { return name; }
  std::string Address() const { return address; }

 private:
  std::string name;
  std::string address;
};

std::istream& read(std::istream& is, Person& p) {
  is >> p.name >> p.address;
  return is;
}

std::ostream& print(std::ostream& os, const Person& p) {
  os << p.Name() << " " << p.Address();
  return os;
}

#endif
