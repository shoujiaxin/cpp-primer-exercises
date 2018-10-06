#include <sstream>
#include <string>
#include <vector>

void ReadFile(std::string file, std::vector<std::string>& vec) {
  std::ifstream input(file);
  if (input) {
    std::string line;
    while (getline(input, line)) {
      vec.push_back(line);
    }
  }
}

int main(int argc, char const* argv[]) {
  std::vector<std::string> strVec;
  ReadFile("./input.txt", strVec);

  for (auto& str : strVec) {
    std::istringstream iss(str);
    std::string word;
    while (iss >> word) {
      std::cout << word << std::endl;
    }
  }
  return 0;
}
