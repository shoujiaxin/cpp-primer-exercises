#include <iostream>
#include <numeric>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> ivec = {1, 2, 3, 4, 5, 6};
  std::cout << "Sum: " << accumulate(ivec.begin(), ivec.end(), 0) << std::endl;
  return 0;
}
