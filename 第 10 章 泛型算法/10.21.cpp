#include <iostream>

int main(int argc, char const *argv[]) {
  int ival = 10;
  auto f = [&ival]() -> bool {
    if (ival == 0) {
      return true;
    } else {
      --ival;
      return false;
    }
  };

  while (!f()) {
    std::cout << ival << std::endl;
  }
  return 0;
}
