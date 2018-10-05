#include <iostream>

int main(int argc, char const *argv[]) {
  std::cout << "Enter two numbers:" << std::endl;
  int num1 = 0, num2 = 0;
  std::cin >> num1 >> num2;
  std::cout << "Numbers between " << num1 << " and " << num2 << " are"
            << std::endl;
  if (num1 > num2) {
    int temp = num1;
    num1 = num2;
    num2 = temp;
  }
  for (int val = num1; val <= num2; ++val) {
    std::cout << val << std::endl;
  }

  return 0;
}
