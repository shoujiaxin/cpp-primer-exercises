#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]) {
  string lastWord, currWord;
  unsigned cnt = 0;
  while (cin >> currWord) {
    if (!isupper(currWord[0])) {
      continue;
    }
    if (currWord == lastWord) {
      cout << "\"" << currWord << "\" occurs again!" << endl;
      ++cnt;
      break;
    }
    lastWord = currWord;
  }
  if (cnt == 0) {
    cout << "There is no duplicated word!" << endl;
  }
  return 0;
}
