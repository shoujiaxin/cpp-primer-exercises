#include <iostream>

int main(int argc, char const *argv[]) {
  const int i = 42;
  auto j = i;
  const auto &k = i;
  auto *p = &i;
  const auto j2 = i, &k2 = i;

  std::cout << typeid(j).name() << std::endl;
  std::cout << typeid(k).name() << std::endl;
  std::cout << typeid(p).name() << std::endl;
  std::cout << typeid(j2).name() << std::endl;
  std::cout << typeid(k2).name() << std::endl;
  return 0;
}
