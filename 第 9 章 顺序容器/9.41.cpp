#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<char> svec{'H', 'e', 'l', 'l', 'o', ' ',
                         'W', 'o', 'r', 'l', 'd', '!'};
  std::string str(svec.cbegin(), svec.cend());
  std::cout << str;
  return 0;
}
