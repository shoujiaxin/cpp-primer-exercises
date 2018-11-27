#ifndef HASPTR_H
#define HASPTR_H

#include <iostream>
#include <string>

class HasPtr {
  friend void swap(HasPtr&, HasPtr&);

 public:
 public:
  HasPtr(const std::string& s = std::string()) : ps(new std::string(s)), i(0) {}
  HasPtr(const HasPtr& orig) : ps(new std::string(*orig.ps)), i(orig.i) {}
  HasPtr(HasPtr&& orig) noexcept : ps(orig.ps), i(orig.i) { orig.ps = nullptr; }
  ~HasPtr() { delete ps; }
  HasPtr& operator=(const HasPtr& rhs);
  HasPtr& operator=(HasPtr&&) noexcept;
  bool operator<(const HasPtr& rhs) const { return *ps < *rhs.ps; }

 private:
  std::string* ps;
  int i;
};

HasPtr& HasPtr::operator=(const HasPtr& rhs) {
  auto newp = new std::string(*rhs.ps);  // 第 453 页
  delete ps;
  ps = newp;
  i = rhs.i;
  return *this;
}

HasPtr& HasPtr::operator=(HasPtr&& rhs) noexcept {
  if (this != &rhs) {
    ps = rhs.ps;
    i = rhs.i;
    rhs.ps = nullptr;
  }
  return *this;
}

void swap(HasPtr& lhs, HasPtr& rhs) {
  using std::swap;
  swap(lhs.ps, rhs.ps);
  swap(lhs.i, rhs.i);
  std::cout << "Call swap(HasPtr& lhs, HasPtr& rhs)" << std::endl;
}

#endif
