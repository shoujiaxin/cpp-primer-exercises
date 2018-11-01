#include <forward_list>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> ivec{1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::vector<int> ivec1, ivec2;
  std::forward_list<int> iflst3;
  copy(ivec.cbegin(), ivec.cend(), back_inserter(ivec1));
  copy(ivec.cbegin(), ivec.cend(), inserter(ivec2, ivec2.begin()));
  copy(ivec.cbegin(), ivec.cend(), front_inserter(iflst3));

  std::cout << "Use back_inserter: ";
  for (auto i : ivec1) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::cout << "Use inserter: ";
  for (auto i : ivec2) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  std::cout << "Use front_inserter: ";
  for (auto i : iflst3) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
