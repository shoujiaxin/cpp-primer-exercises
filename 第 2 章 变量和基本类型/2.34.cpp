#include <iostream>

int main(int argc, char const *argv[]) {
  int i = 0, &r = i;
  auto a = r;
  const int ci = i, &cr = ci;
  auto b = ci;
  auto c = cr;
  auto d = &i;
  auto e = &ci;
  auto &g = ci;

  std::cout << "Before: \na = " << a << "\nb = " << b << "\nc = " << c
            << "\nd = " << d << "\ne = " << e << "\ng = " << g << std::endl;

  a = 42;
  b = 42;
  c = 42;
  // d = 42;  // Error!
  // e = 42;  // Error!
  // g = 42;  // Error!

  std::cout << "After: \na = " << a << "\nb = " << b << "\nc = " << c
            << "\nd = " << d << "\ne = " << e << "\ng = " << g << std::endl;
  return 0;
}
