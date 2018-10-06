#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]) {
  do {
    string str1, str2;
    cout << "Please enter two strings to compare: ";
    if (cin >> str1 >> str2) {
      if (str1.size() == str2.size()) {
        cout << "These two strings are as the same length" << endl;
      } else {
        cout << "The shorter one is: "
             << ((str1.size() < str2.size()) ? str1 : str2) << endl;
      }
    }
  } while (cin);
  return 0;
}
