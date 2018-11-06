#include <iostream>
#include <map>
#include <string>

int main(int argc, char const *argv[]) {
  std::multimap<std::string, std::string> authors{
      {"alan", "DMA"}, {"pezy", "LeetCode"}, {"alan", "CLRS"},
      {"wang", "FTP"}, {"pezy", "CP5"},      {"wang", "CPP-Concurrency"}};

  std::string author = "alan";
  std::string work = "DMdA";
  auto beg = authors.find(author);
  auto cnt = authors.count(author);
  while (cnt) {
    if (beg->second == work) {
      authors.erase(beg);
      break;
    }
    ++beg;
    --cnt;
  }

  for (const auto &p : authors)
    std::cout << p.first << " " << p.second << std::endl;
  return 0;
}
