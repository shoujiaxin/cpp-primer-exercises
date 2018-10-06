#include <sstream>
#include <string>

std::istream& ReadData(std::istream& is) {
  std::string data;
  while (is >> data) {
    std::cout << data << std::endl;
  }
  is.clear();
  return is;
}

int main(int argc, char const* argv[]) {
  std::string str = "Hello World!";
  std::istringstream is(str);
  ReadData(is);
  return 0;
}
