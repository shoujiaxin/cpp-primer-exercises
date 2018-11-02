#include <fstream>
#include <vector>

int main(int argc, char const *argv[]) {
  std::ifstream ifs(argv[1]);
  std::ofstream ofs_odd(argv[2]);   // 奇数
  std::ofstream ofs_even(argv[3]);  // 偶数

  std::istream_iterator<int> in_iter(ifs), eof;
  std::ostream_iterator<int> odd_iter(ofs_odd, " ");
  std::ostream_iterator<int> even_iter(ofs_even, "\n");

  std::vector<int> ivec(in_iter, eof);
  for (auto const i : ivec) {
    if (i % 2) {
      // 奇数
      *odd_iter++ = i;
    } else {
      // 偶数
      *even_iter++ = i;
    }
  }

  return 0;
}
