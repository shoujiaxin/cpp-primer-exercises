#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> ivec1 = {1, 3, 5, 7, 9, 12};
  std::vector<int> ivec2 = {1, 3, 9};
  std::vector<int> ivec3 = {1, 3, 5, 7, 9, 12};

  std::cout << (ivec1 == ivec2 ? "true" : "false") << std::endl;
  std::cout << (ivec1 == ivec3 ? "true" : "false") << std::endl;
  return 0;
}
