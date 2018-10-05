#include <iostream>

int main(int argc, char const *argv[]) {
  int ia[10];
  int cnt = 0;
  for (auto &i : ia) {
    i = cnt;
    ++cnt;
  }
  return 0;
}
