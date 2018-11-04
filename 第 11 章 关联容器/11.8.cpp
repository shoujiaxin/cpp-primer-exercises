#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<std::string> words;
  std::string word;
  while (std::cin >> word) {
    if (find(words.cbegin(), words.cend(), word) == words.cend()) {
      words.push_back(word);
    }
  }

  for (auto w : words) {
    std::cout << w << std::endl;
  }
  return 0;
}
