#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

struct Person {
  std::string name;
  std::string address;

  std::string Name() const { return name; }
  std::string Address() const { return address; }
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
