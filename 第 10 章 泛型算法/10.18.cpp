#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void elimDups(std::vector<std::string> &svec) {
  sort(svec.begin(), svec.end());
  auto endUnique = unique(svec.begin(), svec.end());
  svec.erase(endUnique, svec.end());
}

void biggies(std::vector<std::string> &words,
             std::vector<std::string>::size_type sz) {
  elimDups(words);
  stable_sort(words.begin(), words.end(),
              [](const std::string &a, const std::string &b) {
                return a.size() < b.size();
              });
  auto ep = partition(words.begin(), words.end(),
                      [sz](const std::string &a) { return a.size() >= sz; });
  auto count = ep - words.begin();
  std::cout << count << " " << (count > 2 ? "words" : "word") << " of length "
            << sz << " or longer" << std::endl;
  for_each(words.begin(), ep,
           [](const std::string &s) { std::cout << s << " "; });
  std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
  std::vector<std::string> svec{"abc",   "abcdef",  "primer",
                                "fifth", "edition", "hi"};
  biggies(svec, 5);
  return 0;
}
