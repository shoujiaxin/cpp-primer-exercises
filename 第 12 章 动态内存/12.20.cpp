#include <fstream>
#include <iostream>
#include "12.19.h"

int main(int argc, char const *argv[]) {
  std::ifstream input("./12.20_input.txt");
  std::string line;
  StrBlob strBlob;
  StrBlobPtr strBlobPtr(strBlob);
  while (getline(input, line)) {
    strBlob.push_back(line);
  }

  for (decltype(strBlob.size()) i = 0; i != strBlob.size(); ++i) {
    std::cout << strBlobPtr.deref() << std::endl;
    strBlobPtr.incr();
  }
  return 0;
}
