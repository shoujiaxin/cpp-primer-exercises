#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  std::vector<std::string> text;
  std::map<std::string, std::set<int>> rowNum;

  // 读取文件
  std::ifstream infile("./12.28_input.txt");
  std::string line;
  int currRow = 0;
  while (getline(infile, line)) {
    text.push_back(line);

    std::istringstream iss(line);
    std::string word;
    while (iss >> word) {
      rowNum[word].insert(currRow);
    }
    ++currRow;
  }

  while (true) {
    std::string findWord;
    std::cout << "enter word to look for, or q to quit: ";
    if (!(std::cin >> findWord) || findWord == "q") {
      break;
    }

    // 输出结果
    auto cnt =
        (rowNum.find(findWord) == rowNum.end()) ? 0 : rowNum[findWord].size();
    std::cout << findWord << " occurs " << cnt
              << ((cnt > 1) ? " times" : " time") << std::endl;
    auto row_it = rowNum[findWord].begin();
    while (row_it != rowNum[findWord].end()) {
      std::cout << "\t(line " << *row_it << ") " << text.at(*row_it)
                << std::endl;
      ++row_it;
    }
    std::cout << std::endl;
  }

  return 0;
}
