#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char const *argv[]) {
  std::string str;
  int ival;
  std::vector<std::pair<std::string, int>> pairVec;
  while (std::cin >> str >> ival) {
    pairVec.push_back(make_pair(str, ival));
  }
  return 0;
}
