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
  for (decltype(ivec.size()) ix = 1; ix < ivec.size(); ++ix) {
    cout << ivec[ix - 1] + ivec[ix] << ' ';
  }
  cout << endl << "2: " << endl;
  for (decltype(ivec.size()) ix = 0; ix < ivec.size() / 2; ++ix) {
    cout << ivec[ix] + ivec[ivec.size() - ix - 1] << ' ';
  }
  cout << endl;
  return 0;
}
