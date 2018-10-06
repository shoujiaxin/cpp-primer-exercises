#include <iostream>
#include "7.12.h"

int main(int argc, char const* argv[]) {
  Sales_data total(std::cin);
  Sales_data trans;
  while (read(std::cin, trans)) {
    if (total.isbn() == trans.isbn())
      total.combine(trans);
    else {
      print(std::cout, total) << std::endl;
      total = trans;
    }
  }
  print(std::cout, total) << std::endl;
  return 0;
}
