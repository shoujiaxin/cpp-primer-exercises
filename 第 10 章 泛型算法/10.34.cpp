#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> ivec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::ostream_iterator<int> osit(std::cout, " ");
  for (auto r_iter = ivec.crbegin(); r_iter != ivec.crend(); ++r_iter) {
    *osit++ = *r_iter;
  }
  return 0;
}
