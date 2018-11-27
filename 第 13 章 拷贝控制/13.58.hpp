#ifndef FOO_H
#define FOO_H

#include <iostream>
#include <vector>

class Foo {
 public:
  Foo sorted() &&;
  Foo sorted() const &;

 private:
  std::vector<int> data;
};

Foo Foo::sorted() && {
  sort(data.begin(), data.end());
  std::cout << "Foo Foo::sorted() &&" << std::endl;
  return *this;
}

// 13.56
// Foo Foo::sorted() const & {
//   Foo ret(*this);
//   std::cout << "Foo Foo::sorted() const &" << std::endl;
//   return ret.sorted();
// }

// 13.57
Foo Foo::sorted() const & {
  std::cout << "Foo Foo::sorted() const &" << std::endl;
  return Foo(*this).sorted();
}

#endif
