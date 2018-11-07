#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Input the length of the string: ";
  int len;
  std::cin >> len;
  char *str = new char[len + 1];
  std::cin >> str;
  std::cout << "Your input: " << str << std::endl;
  return 0;
}
