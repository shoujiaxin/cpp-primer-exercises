#include "13.31.hpp"
#include <algorithm>
#include <vector>

int main(int argc, char const* argv[]) {
  std::vector<HasPtr> vec{HasPtr("c++"), HasPtr("primer"), HasPtr("fifth"),
                          HasPtr("edition")};
  std::sort(vec.begin(), vec.end());

  return 0;
}
