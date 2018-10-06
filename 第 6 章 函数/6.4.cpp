#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void fact() {
  unsigned val, result = 1;
  cout << "Please input a num: ";
  cin >> val;
  for (auto i = val; i > 1; --i) {
    result *= i;
  }
  cout << val << "! is " << result << endl;
}

int main(int argc, char const *argv[]) {
  fact();
  return 0;
}
