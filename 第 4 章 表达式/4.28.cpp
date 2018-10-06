#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
  cout << "Byte(s) of bool: " << sizeof(bool) << endl
       << "Byte(s) of char: " << sizeof(char) << endl
       << "Byte(s) of wchar_t: " << sizeof(wchar_t) << endl
       << "Byte(s) of char16_t: " << sizeof(char16_t) << endl
       << "Byte(s) of char32_t: " << sizeof(char32_t) << endl
       << "Byte(s) of short: " << sizeof(short) << endl
       << "Byte(s) of int: " << sizeof(int) << endl
       << "Byte(s) of long: " << sizeof(long) << endl
       << "Byte(s) of long long: " << sizeof(long long) << endl
       << "Byte(s) of float: " << sizeof(float) << endl
       << "Byte(s) of double: " << sizeof(double) << endl
       << "Byte(s) of long double: " << sizeof(long double) << endl;
  return 0;
}
