#include <vector>
using std::begin;
using std::end;
using std::vector;

int main(int argc, char const *argv[]) {
  int ia[] = {0, 1, 2, 3, 4};
  vector<int> ivec(begin(ia), end(ia));
  return 0;
}
