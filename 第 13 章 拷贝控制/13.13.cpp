#include "13.13.h"
#include <vector>

void f(X x) {}
void f_re(X &x) {}

int main(int argc, char const *argv[]) {
  {
    std::cout << "非引用参数传递：" << std::endl;
    X x1;
    f(x1);
    std::cout << std::endl;
  }

  {
    std::cout << "引用参数传递：" << std::endl;
    X x2;
    f_re(x2);
    std::cout << std::endl;
  }

  {
    std::cout << "动态分配：" << std::endl;
    auto xp = new X;
    delete xp;
  }

  {
    std::cout << "存放于容器中：" << std::endl;
    X x3;
    std::vector<X> xVec(3, x3);
    std::cout << std::endl;
  }

  return 0;
}
