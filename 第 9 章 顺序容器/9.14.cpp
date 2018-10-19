#include <iostream>
#include <list>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  std::list<std::string> sl{"Hello", ", ", "World"};
  std::vector<std::string> sv;
  sv.assign(sl.begin(), sl.end());

  for (auto s : sv) {
    std::cout << s;
  }
  return 0;
}
