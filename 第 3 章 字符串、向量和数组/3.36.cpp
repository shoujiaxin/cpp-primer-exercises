#include <iostream>
#include <vector>
using std::begin;
using std::cout;
using std::end;
using std::endl;
using std::vector;

int main(int argc, char const *argv[]) {
  // 比较数组
  int ia1[4] = {1, 2, 3, 4};
  int ia2[4] = {1, 2, 3, 4};
  auto sz1 = end(ia1) - begin(ia1);
  auto sz2 = end(ia2) - begin(ia2);
  if (sz1 != sz2) {
    cout << "数组不相等！" << endl;
  } else {
    for (size_t i = 0; i != sz1; ++i) {
      if (ia1[i] != ia2[i]) {
        cout << "数组不相等！" << endl;
        break;
      }
      if (i == sz1 - 1) {
        cout << "数组相等！" << endl;
      }
    }
  }
  // 比较 vector
  vector<int> ivec1{1, 2, 3, 4};
  vector<int> ivec2{1, 2, 3, 4};
  if (ivec1 == ivec2) {
    cout << "vector 相等" << endl;
  } else {
    cout << "vector 不相等" << endl;
  }
  return 0;
}
