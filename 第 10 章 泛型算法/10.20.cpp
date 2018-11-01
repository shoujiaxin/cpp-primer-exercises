#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<std::string> words;
  std::string word;
  while (std::cin >> word) {
    words.push_back(word);
  }

  std::cout << std::endl
            << count_if(words.begin(), words.end(),
                        [](std::string str) {
                          return str.size() > 6 ? true : false;
                        })
            << std::endl;
  return 0;
}
