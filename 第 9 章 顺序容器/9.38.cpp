#include <iostream>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> ivec;
  for (decltype(ivec.size()) ix = 0; ix != 100; ++ix) {
    ivec.push_back(ix);
    std::cout << "ivec: size: " << ivec.size()
              << " capacity: " << ivec.capacity() << std::endl;
  }
  return 0;
}
