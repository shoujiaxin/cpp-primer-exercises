#include <iostream>
#include <map>
#include <set>
#include <string>

int main(int argc, char const *argv[]) {
  std::multimap<std::string, std::string> authors{
      {"alan", "DMA"}, {"pezy", "LeetCode"}, {"alan", "CLRS"},
      {"wang", "FTP"}, {"pezy", "CP5"},      {"wang", "CPP-Concurrency"}};
  std::map<std::string, std::set<std::string>> order_authors;
  for (const auto &author : authors) {
    order_authors[author.first].insert(author.second);
  }

  for (const auto &author : order_authors) {
    for (const auto &work : author.second) {
      std::cout << author.first << ": ";
      std::cout << work << " " << std::endl;
    }
  }
  return 0;
}
