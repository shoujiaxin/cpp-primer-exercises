#include <algorithm>
#include <iostream>
#include <iterator>
#include <list>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> ivec{1, 2, 2, 3, 3, 3, 4, 4, 5};
  std::list<int> ilst;
  unique_copy(ivec.cbegin(), ivec.cend(), back_inserter(ilst));
  for (const auto i : ilst) {
    std::cout << i << " ";
  }
  std::cout << std::endl;
  return 0;
}
