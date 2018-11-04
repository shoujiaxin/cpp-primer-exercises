#include <algorithm>
#include <iostream>
#include <map>
#include <string>

int main(int argc, char const *argv[]) {
  std::map<std::string, size_t> word_count;
  std::string word;
  while (std::cin >> word) {
    word.erase(remove_if(word.begin(), word.end(),
                         [](const char c) { return ispunct(c); }));
    transform(word.begin(), word.end(), word.begin(), [](char c) {
      return tolower(c);
    });  // std::transform applies the given function to a range and stores the
         // result in another range.
    ++word_count[word];
  }
  for (const auto &w : word_count) {
    std::cout << w.first << " occurs " << w.second
              << ((w.second > 1) ? " times" : " time") << std::endl;
  }
  return 0;
}
