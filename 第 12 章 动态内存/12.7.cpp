#include <iostream>
#include <memory>
#include <vector>

std::shared_ptr<std::vector<int>> NewVector() {
  return std::make_shared<std::vector<int>>();
}

void GetVector(std::shared_ptr<std::vector<int>> ivec) {
  int ival;
  while (std::cin >> ival) {
    ivec->push_back(ival);
  }
}

void PrintVector(std::shared_ptr<std::vector<int>> ivec) {
  for (const auto i : *ivec) {
    std::cout << i << std::endl;
  }
}

int main(int argc, char const* argv[]) {
  auto vec_ptr = NewVector();
  GetVector(vec_ptr);
  PrintVector(vec_ptr);
  return 0;
}
