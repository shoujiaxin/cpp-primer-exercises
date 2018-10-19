#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<std::string> isvec{"1", "2", "10", "42"};
  int isum = 0;
  for (const auto is : isvec) {
    isum += stoi(is);
  }
  std::cout << "Sum of int: " << isum << std::endl;

  std::vector<std::string> dsvec{"1.5", "2.6", "10.7", "42.8"};
  double dsum = 0;
  for (const auto ds : dsvec) {
    dsum += stod(ds);
  }
  std::cout << "Sum of double: " << dsum << std::endl;
  return 0;
}
