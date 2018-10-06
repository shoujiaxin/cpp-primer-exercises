#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]) {
  string str1 = argv[1], str2 = argv[2];
  cout << str1 + str2 << endl;
  return 0;
}
