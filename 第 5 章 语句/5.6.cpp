#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[]) {
  int grade;
  const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
  string letterGrade =
      (grade < 60)
          ? scores[0]
          : scores[(grade - 50) / 10] +
                ((grade == 100)
                     ? ""
                     : (grade % 10 > 7) ? "+" : (grade % 10 < 3) ? "-" : "");

  cout << letterGrade << endl;
  return 0;
}
