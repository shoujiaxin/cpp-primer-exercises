#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]) {
  string str = "Hello World!";
  for (char c : str) {
    c = 'X';
  }
  cout << str << endl;
  return 0;
}
