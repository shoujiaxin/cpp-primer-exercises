#include <cstring>
#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
  char str1[] = "hello";
  char str2[] = "world";
  char str3[11];
  strcpy(str3, str1);
  strcat(str3, str2);
  cout << str3 << endl;
  return 0;
}
