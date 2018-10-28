#include <algorithm>
#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
  int num;
  std::cout << "Input a number to count: ";
  std::cin >> num;

  std::vector<int> ivec;
  int val;
  while (std::cin >> val) {
    ivec.push_back(val);
  }

  int cnt = count(ivec.cbegin(), ivec.cend(), num);
  std::cout << num << " occurs " << cnt << (cnt > 1 ? " times" : " time")
            << std::endl;
  return 0;
}
