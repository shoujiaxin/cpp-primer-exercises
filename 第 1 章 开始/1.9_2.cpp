#include <iostream>

int main(int argc, char const *argv[]) {
  int sum = 0;
  for (int val = 50; val <= 100; ++val) {
    sum += val;
  }
  std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl
            << std::endl;

  return 0
}
