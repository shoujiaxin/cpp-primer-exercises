#include <fstream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  std::string line, word;
  std::vector<PersonInfo> people;
  std::ifstream is("./input.txt");
  while (getline(is, line)) {
    PersonInfo info;
    istringstream record(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
  }
  return 0;
}
