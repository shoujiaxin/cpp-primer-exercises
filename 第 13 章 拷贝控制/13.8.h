#ifndef HASPTR_H
#define HASPTR_H

#include <string>

class HasPtr {
 public:
  HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr& orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
  HasPtr& operator=(const HasPtr& rhs) {
    delete ps;
    ps = nullptr;
    ps = new std::string(*rhs.ps);
    i = rhs.i;
    return *this;
  }

 private:
  std::string* ps;
  int i;
};

#endif
