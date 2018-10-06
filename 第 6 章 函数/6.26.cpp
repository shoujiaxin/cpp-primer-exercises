#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
  for (size_t i = 0; i != argc; ++i) {
    cout << argv[i] << endl;
  }
  return 0;
}
