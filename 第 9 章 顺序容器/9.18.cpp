#include <deque>
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  std::deque<std::string> strDeque;
  std::string str;
  while (std::cin >> str) {
    strDeque.push_back(str);
  }

  for (auto it = strDeque.begin(); it != strDeque.end(); ++it) {
    std::cout << *it << std::endl;
  }
  return 0;
}
