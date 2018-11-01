#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main(int argc, char const *argv[]) {
  std::ifstream ifs("./10.12_input.txt");
  std::istream_iterator<std::string> str_it(ifs), eof;
  std::ostream_iterator<std::string> str_out(std::cout, "\n");
  std::vector<std::string> svec(str_it, eof);

  for (const auto &s : svec) {
    std::cout << s << std::endl;
  }
  return 0;
}
