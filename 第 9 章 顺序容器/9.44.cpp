#include <iostream>
#include <string>

void Replace(std::string &s, const std::string &oldVal,
             const std::string &newVal) {
  auto ix = oldVal.size();
  while (ix <= s.size() + 1) {
    if (s.substr(ix - oldVal.size(), oldVal.size()) == oldVal) {
      s.replace(ix - oldVal.size(), oldVal.size(), newVal);
      ix += newVal.size();
    } else {
      ++ix;
    }
  }
}

int main(int argc, char const *argv[]) {
  std::string str = "tho abc thru 123 tho";
  Replace(str, "tho", "though");
  Replace(str, "thru", "through");
  std::cout << str << std::endl;
  return 0;
}
