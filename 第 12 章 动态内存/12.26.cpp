#include <iostream>
#include <memory>
#include <string>

int main(int argc, char const *argv[]) {
  std::allocator<std::string> alloc;
  const int n = 10;
  const auto p = alloc.allocate(n);
  auto q = p;
  std::string s;
  while (std::cin >> s) {
    *q++ = s;
  }
  const size_t size = q - p;

  while (q != p) {
    alloc.destroy(--q);
  }
  alloc.deallocate(p, n);

  std::cout << "Number of input strings: " << size << std::endl;
  return 0;
}
