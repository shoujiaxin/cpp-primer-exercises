#include <iostream>
using std::begin;
using std::cout;
using std::end;
using std::endl;

void print(int val) { cout << val << endl; }

void print(int *beg, int *end) {
  while (beg != end) {
    cout << *beg++ << endl;
  }
}

int main(int argc, char const *argv[]) {
  int i = 0, j[2] = {0, 1};
  print(i);
  print(begin(j), end(j));
  return 0;
}
