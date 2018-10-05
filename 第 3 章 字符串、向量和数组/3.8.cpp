#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]) {
  string str = "Hello World!";
  decltype(str.size()) index = 0;
  while (index < str.size()) {
    str[index] = 'X';
    ++index;
  }
  cout << str << endl;
  for (index = 0; index < str.size(); ++index) {
    str[index] = 'X';
  }
  cout << str << endl;
  return 0;
}
