#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<int> vi = {0, 1, 2, 3, 4};
  auto iter = vi.begin();
  while (iter != vi.end())
    if (*iter % 2) iter = vi.insert(iter, *iter);
  ++iter;
  return 0;
}
