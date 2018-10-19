#include <iostream>
#include <list>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> ivec1 = {1, 3, 5, 7, 9, 12};
  std::list<int> il1 = {1, 3, 9};
  std::vector<int> ivec2(il1.begin(), il1.end());
  std::list<int> il2 = {1, 3, 5, 7, 9, 12};
  std::vector<int> ivec3(il2.begin(), il2.end());

  std::cout << (ivec1 == ivec2 ? "true" : "false") << std::endl;
  std::cout << (ivec1 == ivec3 ? "true" : "false") << std::endl;
  return 0;
}
