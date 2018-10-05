#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::string;
using std::vector;

int main(int argc, char const *argv[]) {
  string inputStr;
  vector<string> svec;
  while (cin >> inputStr) {
    svec.push_back(inputStr);
  }
  return 0;
}
