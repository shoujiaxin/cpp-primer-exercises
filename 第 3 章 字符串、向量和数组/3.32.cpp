#include <iostream>
#include <vector>
using std::vector;

int main(int argc, char const *argv[]) {
  int ia[10], ia2[10];
  int cnt = 0;
  for (auto &i : ia) {
    i = cnt;
    ++cnt;
  }
  for (size_t i = 0; i < 10; ++i) {
    ia2[i] = ia[i];
  }
  vector<int> ivec(10);
  for (auto it = ivec.begin(); it != ivec.end(); ++it) {
    *it = it - ivec.begin();
  }
  return 0;
}
