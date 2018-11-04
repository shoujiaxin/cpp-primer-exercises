#include <iostream>
#include <map>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  std::map<std::string, std::vector<std::string>> family;
  std::string familyName;
  while (std::cin >> familyName) {
    std::string childName;
    while (std::cin >> childName) {
      family[familyName].push_back(childName);
    }
  }
  return 0;
}
