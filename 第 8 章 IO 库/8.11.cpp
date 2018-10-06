#include <sstream>
#include <string>
#include <vector>

struct PersonInfo {
  std::string name;
  std::vector<std::stirng> phones;
};

int main(int argc, char const *argv[]) {
  std::string line, word;
  std::vector<PersonInfo> people;
  std::istringstream record;
  while (getline(std::cin, line)) {
    PersonInfo info;
    record.str(line);
    record >> info.name;
    while (record >> word) {
      info.phones.push_back(word);
    }
    people.push_back(info);
    record.clear();
  }
  return 0;
}
