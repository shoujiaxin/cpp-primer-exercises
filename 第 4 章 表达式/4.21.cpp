#include <vector>
using std::vector;

int main(int argc, char const *argv[]) {
  vector<int> ivec{0, 1, 2, 3, 5};
  for (auto &i : ivec) {
    i = (i % 2 == 0) ? i : i * 2;
  }
  return 0;
}
