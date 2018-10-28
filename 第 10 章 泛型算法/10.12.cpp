#include <fstream>
#include <vector>
#include "Sales_data.h"

bool compareIsbn(const Sales_data& data1, const Sales_data& data2) {
  return data1.isbn() < data2.isbn();
}

int main(int argc, char const* argv[]) {
  std::ifstream input("./10.12_input.txt");
  std::vector<Sales_data> dataVec;
  Sales_data data;
  while (read(input, data)) {
    dataVec.push_back(data);
  }

  sort(dataVec.begin(), dataVec.end(), compareIsbn);

  for (const auto& d : dataVec) {
    print(std::cout, d) << std::endl;
  }
  return 0;
}
