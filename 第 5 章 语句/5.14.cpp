#include <iostream>
#include <string>
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]) {
  string lastStr, currStr;
  unsigned cnt = 1, wordCnt = 0;
  while (cin >> currStr) {
    if (currStr == lastStr) {
      ++cnt;
    } else {
      if (cnt > 1) {
        cout << lastStr << " 连续出现 " << cnt << " 次\n";
        ++wordCnt;
      }
      cnt = 1;
    }
    lastStr = currStr;
  }
  if (cnt > 1) {
    cout << lastStr << " 连续出现 " << cnt << " 次\n";
  } else if (wordCnt == 0) {
    cout << "没有连续出现的单词\n";
  }
  return 0;
}
