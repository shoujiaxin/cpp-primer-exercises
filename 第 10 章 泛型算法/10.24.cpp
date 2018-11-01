#include <algorithm>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std::placeholders;

bool check_size(const int val, const std::string &str) {
  return val > str.size();
}

int main(int argc, char const *argv[]) {
  std::string str{"C++ Primer 5th Edition"};
  std::vector<int> ivec{0, 2, 4, 23, 2};
  auto it = find_if(ivec.begin(), ivec.end(), std::bind(check_size, _1, str));
  if (it != ivec.end()) {
    std::cout << *it << std::endl;
  }
  return 0;
}
