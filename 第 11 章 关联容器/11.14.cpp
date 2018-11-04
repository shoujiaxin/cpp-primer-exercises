#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

int main(int argc, char const *argv[]) {
  std::map<std::string, std::vector<std::pair<std::string, std::string>>>
      family;
  std::string familyName;
  while (std::cin >> familyName) {
    std::string childName;
    std::string childBirthday;
    while (std::cin >> childName >> childBirthday) {
      family[familyName].push_back(make_pair(childName, childBirthday));
    }
  }
  return 0;
}
