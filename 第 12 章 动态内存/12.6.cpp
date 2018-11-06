#include <iostream>
#include <vector>

std::vector<int>* NewVector() { return new std::vector<int>; }

void GetVector(std::vector<int>* ivec) {
  int ival;
  while (std::cin >> ival) {
    ivec->push_back(ival);
  }
}

void PrintVector(std::vector<int>* ivec) {
  for (const auto i : *ivec) {
    std::cout << i << std::endl;
  }
}

int main(int argc, char const* argv[]) {
  auto vec_ptr = NewVector();
  GetVector(vec_ptr);
  PrintVector(vec_ptr);
  delete vec_ptr;
  return 0;
}
