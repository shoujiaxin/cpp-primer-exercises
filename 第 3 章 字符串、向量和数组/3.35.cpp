#include <iostream>
using std::begin;
using std::end;

int main(int argc, char const *argv[]) {
  int ia[4] = {1, 2, 3, 4};
  for (auto p = begin(ia); p != end(ia); ++p) {
    *p = 0;
  }
  return 0;
}
