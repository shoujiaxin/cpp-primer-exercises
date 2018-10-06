#include <string>
using std::string;

int main(int argc, char const *argv[]) {
  // 只使用条件运算符
  string finalGrade =
      (grade > 90) ? "high pass"
                   : (grade > 75) ? "pass" : (grade < 60) ? "fail" : "low pass";
  // 使用 if 语句
  if (grade > 90)
    finalGrade = "high pass";
  else if (grade > 75)
    finalGrade = "pass";
  else if (grade < 60)
    finalGrade = "fail";
  else
    finalGrade = "low pass";
  return 0;
}
