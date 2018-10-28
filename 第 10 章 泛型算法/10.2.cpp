#include <algorithm>
#include <iostream>
#include <list>
#include <string>

int main(int argc, char const *argv[]) {
  std::string str;
  std::cout << "Input a string to count: ";
  std::cin >> str;

  std::list<std::string> slst;
  std::string s;
  while (std::cin >> s) {
    slst.push_back(s);
  }

  int cnt = count(slst.cbegin(), slst.cend(), str);
  std::cout << str << " occurs " << cnt << (cnt > 1 ? " times" : " time")
            << std::endl;
  return 0;
}
