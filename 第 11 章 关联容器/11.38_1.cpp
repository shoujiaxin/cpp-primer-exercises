#include <iostream>
#include <string>
#include <unordered_map>

int main(int argc, char const *argv[]) {
  std::unordered_map<std::string, std::size_t> word_count;
  std::string word;
  while (std::cin >> word) {
    ++word_count[word];
  }

  for (const auto &w : word_count) {
    std::cout << w.first << " occurs " << w.second
              << ((w.second > 1) ? "times" : "time") << std::endl;
  }
  return 0;
}
