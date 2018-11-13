#include <iostream>

class numbered {
 public:
  numbered() : mysn(sn++) {}
  numbered(const numbered& orig) : mysn(sn++) {}

  int mysn;
  static int sn;
};

void f(numbered s) { std::cout << s.mysn << std::endl; }

int numbered::sn = 0;

int main(int argc, char const* argv[]) {
  numbered a, b = a, c = b;
  std::cout << "a.mysn: " << a.mysn << std::endl;
  std::cout << "b.mysn: " << b.mysn << std::endl;
  std::cout << "c.mysn: " << c.mysn << std::endl;
  f(a);
  f(b);
  f(c);
  return 0;
}
