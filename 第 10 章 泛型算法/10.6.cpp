#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> ivec;
  fill_n(back_inserter(ivec), 10, 0);

  for (auto i : ivec) {
    std::cout << i << std::endl;
  }
  return 0;
}
