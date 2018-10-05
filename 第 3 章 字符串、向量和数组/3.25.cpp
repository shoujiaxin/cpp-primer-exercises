#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[]) {
  vector<unsigned> scores(11, 0);
  auto it = scores.begin();
  unsigned grade;
  while (cin >> grade) {
    if (grade <= 100) {
      ++(*(it + grade / 10));
    }
  }
  for (auto s : scores) {
    cout << s << ' ';
  }
  cout << endl;
  return 0;
}
