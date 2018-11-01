#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void elimDups(std::vector<std::string> &svec) {
  sort(svec.begin(), svec.end());
  auto endUnique = unique(svec.begin(), svec.end());
  svec.erase(endUnique, svec.end());
}

bool isShorter(const std::string &s1, const std::string &s2) {
  return s1.size() < s2.size();
}

int main(int argc, char const *argv[]) {
  std::vector<std::string> words;
  std::string word;
  while (std::cin >> word) {
    words.push_back(word);
  }

  elimDups(words);
  stable_sort(words.begin(), words.end(), isShorter);

  for (const auto &w : words) {
    std::cout << w << " ";
  }
  std::cout << std::endl;
  return 0;
}
