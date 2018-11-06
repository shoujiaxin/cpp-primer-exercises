#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>

std::map<std::string, std::string> buildMap(std::ifstream &map_file) {
  std::map<std::string, std::string> trans_map;
  std::string key;
  std::string value;
  while (map_file >> key && getline(map_file, value)) {
    if (value.size() > 1) {
      trans_map[key] = value.substr(1);
    } else {
      throw std::runtime_error("no rule for " + key);
    }
  }
  return trans_map;
}

const std::string &transform(const std::string &s,
                             const std::map<std::string, std::string> &m) {
  auto map_it = m.find(s);
  if (map_it != m.cend()) {
    return map_it->second;
  } else {
    return s;
  }
}

void word_transform(std::ifstream &map_file, std::ifstream &input) {
  auto trans_map = buildMap(map_file);
  std::string text;
  while (getline(input, text)) {
    std::istringstream sstream(text);
    std::string word;
    std::ostream_iterator<std::string> out_iter(std::cout, " ");
    while (sstream >> word) {
      *out_iter++ = transform(word, trans_map);
    }
    std::cout << std::endl;
  }
}

int main(int argc, char const *argv[]) {
  std::ifstream map_file("./11.33_map.txt");
  std::ifstream input("./11.33_input.txt");
  word_transform(map_file, input);
  return 0;
}
