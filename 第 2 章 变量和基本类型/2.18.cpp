int main(int argc, char const *argv[]) {
  int val1 = 102;
  int val2 = 300;
  int *p = &val1;
  *p = 2;     // 更改指针所指对象的值
  p = &val2;  // 更改指针的值
  return 0;
}
