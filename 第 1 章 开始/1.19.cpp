#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Enter two numbers:" << std::endl;
  int num1 = 0, num2 = 0;
  std::cin >> num1 >> num2;
  std::cout << "Numbers between " << num1 << " and " << num2 << " are"
            << std::endl;
  while (num1 != num2) {
    std::cout << num1 << std::endl;
    if (num1 < num2) {
      ++num1;
    } else {
      --num1;
    }
  }
  std::cout << num2 << std::endl;
  return 0;
}
