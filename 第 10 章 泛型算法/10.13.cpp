#include <iostream>
#include <string>
#include <vector>

bool isLongerThanFour(const std::string &str) {
  if (str.size() >= 5) {
    return true;
  }
  return false;
}

int main(int argc, char const *argv[]) {
  std::vector<std::string> words;
  std::string word;
  while (std::cin >> word) {
    words.push_back(word);
  }
  auto end_partition = partition(words.begin(), words.end(), isLongerThanFour);
  words.erase(end_partition, words.end());
  for (const auto &s : words) {
    std::cout << s << std::endl;
  }
  return 0;
}
