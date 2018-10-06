#include <iostream>
#include <vector>
using std::cout;
using std::vector;

void PrintVectorSize(vector<int>::const_iterator beg,
                     vector<int>::const_iterator end) {
  cout << *beg;
  if (end - beg > 1) {
    PrintVectorSize(++beg, end);
  }
}

int main(int argc, char const* argv[]) {
  vector<int> iv = {0, 1, 2, 3, 4};
  PrintVectorSize(iv.cbegin(), iv.cend());
  return 0;
}
