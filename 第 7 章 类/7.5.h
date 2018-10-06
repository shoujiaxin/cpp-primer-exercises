#ifndef PERSON_H
#define PERSON_H

#include <string>

struct Person {
  std::string name;
  std::string address;

  std::string Name() const { return name; }
  std::string Address() const { return address; }
};

#endif
