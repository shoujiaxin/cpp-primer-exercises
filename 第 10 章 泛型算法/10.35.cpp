#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::ostream_iterator<int> osit(std::cout, " ");
  auto iter = ivec.cend();
  while (iter != ivec.cbegin()) {
    iter--;
    *osit++ = *iter;
  }
  return 0;
}
