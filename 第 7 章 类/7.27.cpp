#include "7.27.h"
#include <iostream>

int main(int argc, char const *argv[]) {
  Screen myScreen(5, 5, 'X');
  myScreen.move(4, 0).set('#').display(std::cout);
  std::cout << "\n";
  myScreen.display(std::cout);
  std::cout << "\n";
  return 0;
}
