#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>

int main(int argc, char const *argv[]) {
  std::istream_iterator<int> in_iter(std::cin), eof;
  std::ostream_iterator<int> out_iter(std::cout, " ");
  std::vector<int> ivec;

  copy(in_iter, eof, back_inserter(ivec));

  sort(ivec.begin(), ivec.end());

  copy(ivec.begin(), ivec.end(), out_iter);
  std::cout << std::endl;
  return 0;
}
