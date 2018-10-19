#include <list>
#include <vector>

int main(int argc, char const *argv[]) {
  int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
  std::vector<int> ivec;
  std::list<int> ilst;
  for (auto i : ia) {
    ivec.push_back(i);
    ilst.push_back(i);
  }

  for (auto it = ivec.begin(); it != ivec.end(); ++it) {
    if (!((*it) % 2)) {
      ivec.erase(it);
    }
  }
  for (auto it = ilst.begin(); it != ilst.end(); ++it) {
    if ((*it) % 2) {
      ilst.erase(it);
    }
  }
  return 0;
}
