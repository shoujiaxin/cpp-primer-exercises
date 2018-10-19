#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char const *argv[]) {
  std::ifstream inputFile("./9.49_input.txt");
  const std::string ascender{"bdfhkl"};
  const std::string descender{"gjpqy"};

  std::string word;
  std::string::size_type maxSize = 0;
  std::string maxSizeWord;
  while (inputFile >> word) {
    if (word.find_first_of(ascender) == std::string::npos &&
        word.find_first_of(descender) == std::string::npos &&
        word.size() > maxSize) {
      maxSize = word.size();
      maxSizeWord = word;
    }
  }
  std::cout << maxSizeWord << std::endl;
  return 0;
}
