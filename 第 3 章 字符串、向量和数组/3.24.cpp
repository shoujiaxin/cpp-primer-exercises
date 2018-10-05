#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

int main(int argc, char const *argv[]) {
  int num;
  vector<int> ivec;
  while (cin >> num) {
    ivec.push_back(num);
  }
  cout << "1: " << endl;
  for (auto it = ivec.begin(); it < ivec.end() - 1; ++it) {
    cout << *it + *(it + 1) << ' ';
  }
  cout << endl << "2: " << endl;
  for (auto it = ivec.begin();
       it < ivec.begin() + (ivec.end() - ivec.begin()) / 2; ++it) {
    cout << *it + *(ivec.end() - (it - ivec.begin()) - 1) << ' ';
  }
  cout << endl;
  return 0;
}
