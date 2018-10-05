#include <cstring>
#include <iostream>
#include <string>
using std::cout;
using std::endl;
using std::string;

int main(int argc, char const *argv[]) {
  // 比较两个 string 对象
  string str1 = "hello";
  string str2 = "world";
  if (str1 == str2) {
    cout << "两个 string 相等" << endl;
  } else {
    cout << "两个 string 不相等" << endl;
  }
  // 比较两个 C 风格字符串
  const char cstr1[] = "hello";
  const char cstr2[] = "hello";
  if (strcmp(cstr1, cstr2) == 0) {
    cout << "两个 C 风格字符串相等" << endl;
  } else {
    cout << "两个 C 风格字符串不相等" << endl;
  }
  return 0;
}
