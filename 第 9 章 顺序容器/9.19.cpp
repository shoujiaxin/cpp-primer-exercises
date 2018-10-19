#include <iostream>
#include <list>
#include <string>

int main(int argc, char const *argv[]) {
  std::list<std::string> strList;
  std::string str;
  while (std::cin >> str) {
    strList.push_back(str);
  }

  for (auto it = strList.begin(); it != strList.end(); ++it) {
    std::cout << *it << std::endl;
  }
  return 0;
}
