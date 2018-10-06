#include <iostream>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main(int argc, char const *argv[]) {
  vector<int> ivec1{0, 1, 1, 2}, ivec2{0, 1, 1, 2, 3, 5, 8};
  auto sz1 = ivec1.size(), sz2 = ivec2.size();
  if (sz1 != sz2) {
    for (decltype(sz1) ix = 0, sz = (sz1 < sz2) ? sz1 : sz2;
         ix < sz && ivec1[ix] == ivec2[ix]; ++ix) {
      if (ix == sz - 1) {
        cout << "true" << endl;
      }
    }
  }
  return 0;
}
