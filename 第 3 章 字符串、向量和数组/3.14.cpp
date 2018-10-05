#include <iostream>
#include <vector>
using std::cin;
using std::vector;

int main(int argc, char const *argv[]) {
  int inputNum;
  vector<int> ivec;
  while (cin >> inputNum) {
    ivec.push_back(inputNum);
  }
  return 0;
}
