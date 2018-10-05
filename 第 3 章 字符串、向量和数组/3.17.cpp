#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[]) {
  string word;
  vector<string> svec;
  while (cin >> word) {
    svec.push_back(word);
  }
  for (auto str : svec) {
    for (auto &c : str) {
      c = toupper(c);
    }
    cout << str << endl;
  }
  return 0;
}
