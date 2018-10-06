#include <iostream>
using std::cin;

int main(int argc, char const *argv[]) {
  unsigned ffCnt = 0, flCnt = 0, fiCnt = 0;
  char ch;
  while (cin >> ch) {
    switch (ch) {
      case 'f':
        cin >> ch;
        switch (ch) {
          case 'f':
            ++ffCnt;
            break;
          case 'l':
            ++flCnt;
            break;
          case 'i':
            ++fiCnt;
            break;
        }
    }
  }
  return 0;
}
