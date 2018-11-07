#include <memory>

int main(int argc, char const *argv[]) {
  std::unique_ptr<int> up1(new int(100));
  std::unique_ptr<int> up2;
  up2 = up1;  // error
  return 0;
}
