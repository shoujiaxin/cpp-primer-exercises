#include "7.11.h"
#include <iostream>

int main(int argc, char const* argv[]) {
  Sales_data data1;
  Sales_data data2("0-201-78345-X");
  Sales_data data3("0-201-78345-X", 3, 20);
  Sales_data data4(std::cin);
  return 0;
}
