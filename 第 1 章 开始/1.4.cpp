#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Enter two numbers:" << std::endl;
  int num1 = 0, num2 = 0;
  std::cin >> num1 >> num2;
  std::cout << "The product of " << num1 << " and " << num2 << " is "
            << num1 * num2 << std::endl;
  return 0;
}
