#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> v = {0, 1, 2, 3, 4};
  auto begin = v.begin();
  while (begin != v.end()) {
    ++begin;
    v.insert(begin, 42);
    ++begin;
  }
  return 0;
}
