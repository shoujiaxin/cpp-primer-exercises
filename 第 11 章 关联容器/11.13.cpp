#include <iostream>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char const *argv[]) {
  std::string str;
  int ival;
  std::vector<std::pair<std::string, int>> pairVec1;
  std::vector<std::pair<std::string, int>> pairVec2;
  std::vector<std::pair<std::string, int>> pairVec3;
  while (std::cin >> str >> ival) {
    pairVec1.push_back(make_pair(str, ival));
    pairVec2.push_back({str, ival});
    pairVec3.push_back(std::pair<std::string, int>(str, ival));
  }
  return 0;
}
