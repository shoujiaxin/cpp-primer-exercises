#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int func(int, int);
vector<decltype(func) *> vec;

int add(int val1, int val2) { return val1 + val2; }
int minus(int val1, int val2) { return val1 - val2; }
int multiply(int val1, int val2) { return val1 * val2; }
int divide(int val1, int val2) { return val1 / val2; }

int main(int argc, char const *argv[]) {
  vec.push_back(add);
  vec.push_back(minus);
  vec.push_back(multiply);
  vec.push_back(divide);

  for (auto f : vec) {
    cout << f(1, 2) << endl;
  }
  return 0;
}
