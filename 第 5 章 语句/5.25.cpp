#include <iostream>
using std::cin;
using std::cout;
using std::endl;
using std::runtime_error;

int main(int argc, char const *argv[]) {
  int ival1, ival2;
  while (cin >> ival1 >> ival2) {
    try {
      if (ival2 == 0) {
        throw runtime_error("The dividend can't be zero!");
      }
      cout << ival1 << " / " << ival2 << " = "
           << static_cast<double>(ival1) / ival2 << endl;
    } catch (runtime_error err) {
      cout << err.what() << endl << "Try Again? Enter yes(y) or no(n)" << endl;
      char c;
      cin >> c;
      if (!c || c == 'n') {
        break;
      }
    }
  }
  return 0;
}
