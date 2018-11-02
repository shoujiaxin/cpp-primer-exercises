#include <algorithm>
#include <iostream>
#include <list>
#include <string>

void elimDups(std::list<std::string> &slst) {
  slst.sort();
  slst.unique();
}

int main(int argc, char const *argv[]) {
  std::list<std::string> words;
  std::string word;
  while (std::cin >> word) {
    words.push_back(word);
  }

  elimDups(words);
  for (const auto s : words) {
    std::cout << s << std::endl;
  }
  return 0;
}
