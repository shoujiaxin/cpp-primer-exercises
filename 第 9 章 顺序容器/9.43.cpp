#include <iostream>
#include <string>

void Replace(std::string &s, const std::string &oldVal,
             const std::string &newVal) {
  auto iter = s.begin() + oldVal.size();
  while (iter != s.end()) {
    if (std::string(iter - oldVal.size(), iter) == oldVal) {
      iter = s.erase(iter - oldVal.size(), iter);
      iter = s.insert(iter, newVal.begin(), newVal.end());
      iter += newVal.size();
    } else {
      ++iter;
    }
  }
  if (std::string(iter - oldVal.size(), iter) == oldVal) {
    iter = s.erase(iter - oldVal.size(), iter);
    iter = s.insert(iter, newVal.begin(), newVal.end());
  }
}

int main(int argc, char const *argv[]) {
  std::string str = "tho abc thru 123 tho";
  Replace(str, "tho", "though");
  Replace(str, "thru", "through");
  std::cout << str << std::endl;
  return 0;
}
