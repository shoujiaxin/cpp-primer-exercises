#include <iostream>
#include <string>

std::string MakeName(const std::string &name, const std::string &prefix,
                     const std::string &suffix) {
  std::string str{name};
  decltype(str.size()) pos = 0;
  str.insert(pos, prefix);
  pos += str.size();
  str.insert(pos, suffix);
  return str;
}

int main(int argc, char const *argv[]) {
  std::cout << MakeName("sjx", "Mr. ", " III") << std::endl;
  return 0;
}
