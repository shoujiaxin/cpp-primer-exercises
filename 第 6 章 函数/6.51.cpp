#include <iostream>
using std::cout;
using std::endl;

void f() { cout << "void f();" << endl; }

void f(int val) { cout << "void f(int);" << endl; }

void f(int val1, int val2) { cout << "void f(int, int);" << endl; }

void f(double val1, double val2 = 3.14) {
  cout << "void f(double, double = 3.14)" << endl;
}

int main(int argc, char const* argv[]) {
  // f(2.56, 42);  // 二义性
  f(42);
  f(42, 0);
  f(2.56, 3.14);
  return 0;
}
