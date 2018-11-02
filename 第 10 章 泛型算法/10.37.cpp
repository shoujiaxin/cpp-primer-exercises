#include <iostream>
#include <list>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::list<int> ilst(ivec.crbegin() + 3, ivec.crend() - 2);  // 左闭合区间
  for (const auto i : ilst) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
