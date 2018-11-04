#include <iostream>
#include <map>
#include <string>

int main(int argc, char const *argv[]) {
  std::multimap<std::string, std::string> family;
  std::string familyName;
  while (std::cin >> familyName) {
    std::string childName;
    while (std::cin >> childName) {
      family.insert({familyName, childName});
    }
  }
  return 0;
}
