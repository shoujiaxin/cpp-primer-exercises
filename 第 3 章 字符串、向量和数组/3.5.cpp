#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]) {
  string str, total1, total2;
  while (cin >> str) {
    total1 += str;
    total2 += str + ' ';
  }
  cout << total1 << endl << total2 << endl;
  return 0;
}
