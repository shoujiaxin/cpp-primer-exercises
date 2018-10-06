#include <fstream>
#include <iostream>
#include "Sales_data.h"

int main(int argc, char const* argv[]) {
  Sales_data total;
  std::ifstream input(argv[1]);
  if (read(input, total)) {
    Sales_data trans;
    while (read(input, trans)) {
      if (total.isbn() == trans.isbn())
        total.combine(trans);
      else {
        print(std::cout, total) << std::endl;
        total = trans;
      }
    }
    print(std::cout, total) << std::endl;
  } else {
    std::cerr << "No data?!" << std::endl;
  }
  return 0;
}
