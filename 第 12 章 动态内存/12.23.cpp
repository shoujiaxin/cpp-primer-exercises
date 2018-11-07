#include <iostream>
#include <string>

int main(int argc, char const* argv[]) {
  // 字符串字面常量
  const char str1[] = "cpp primer fifth edition";
  const char str2[] = " exercises";
  char* str = new char[50];
  strcpy(str, str1);
  strcat(str, str2);
  std::cout << "连接两个字符串字面常量：";
  for (auto c = str; *c != '\0'; ++c) {
    std::cout << *c;
  }
  std::cout << std::endl;
  delete[] str;

  // string 对象
  std::string str3 = "cpp primer fifth edition";
  std::string str4 = " exercises";
  std::cout << "连接两个 string 对象：" << str3 + str4 << std::endl;
  return 0;
}
