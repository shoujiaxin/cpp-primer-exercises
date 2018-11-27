#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
  cout << "Enter two numbers:" << endl;
  int num1 = 0, num2 = 0;
  cin >> num1 >> num2;
  cout << "Numbers between " << num1 << " and " << num2 << " are" << endl;
  while (num1 != num2) {
    cout << num1 << endl;
    ++num1;
  }
  cout << num2 << endl;
  return 0;
}
