#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  const std::string str{"ab2c3d7R4E6"};
  const std::string numbers{"0123456789"};
  std::string::size_type pos = 0;

  // find numbers with find_first_of
  while ((pos = str.find_first_of(numbers, pos)) != std::string::npos) {
    std::cout << str.at(pos);
    ++pos;
  }
  std::cout << std::endl;

  // find letters with find_first_not_of
  pos = 0;
  while ((pos = str.find_first_not_of(numbers, pos)) != std::string::npos) {
    std::cout << str.at(pos);
    ++pos;
  }
  std::cout << std::endl;

  return 0;
}
