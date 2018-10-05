#include <iostream>
#include <vector>
using std::begin;
using std::vector;

int main(int argc, char const *argv[]) {
  vector<int> ivec = {0, 1, 2, 3, 4};
  int ia[5] = {};
  auto p = begin(ia);
  for (auto i : ivec) {
    *p = i;
    ++p;
  }
  return 0;
}
