#include <iostream>
#include <list>
#include <vector>

int main(int argc, char const *argv[]) {
  std::list<int> il{0, 1, 2, 3, 4};
  std::vector<int> iv{5, 6, 7, 8, 9};
  std::vector<double> dv1(il.begin(), il.end());
  std::vector<double> dv2(iv.begin(), iv.end());

  for (auto d : dv1) {
    std::cout << d << std::endl;
  }
  for (auto d : dv2) {
    std::cout << d << std::endl;
  }
  return 0;
}
