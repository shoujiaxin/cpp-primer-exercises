#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

void elimDups(std::vector<std::string> &svec) {
  sort(svec.begin(), svec.end());
  auto endUnique = unique(svec.begin(), svec.end());

  std::cout << "After call unique(): ";
  for (const auto &s : svec) {
    std::cout << s << " ";
  }
  std::cout << svec.size();
  std::cout << std::endl;

  svec.erase(endUnique, svec.end());

  std::cout << "After call erase(): ";
  for (const auto &s : svec) {
    std::cout << s << " ";
  }
  std::cout << svec.size();
  std::cout << std::endl;
}

int main(int argc, char const *argv[]) {
  std::vector<std::string> words;
  std::string word;
  while (std::cin >> word) {
    words.push_back(word);
  }

  std::cout << "After read input: ";
  for (const auto &w : words) {
    std::cout << w << " ";
  }
  std::cout << words.size();
  std::cout << std::endl;

  elimDups(words);
  return 0;
}
