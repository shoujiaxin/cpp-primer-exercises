#include "9.51.h"

int main(int argc, char const *argv[]) {
  Date date1("April 1, 1900");
  Date date2("1/15/1900");
  Date date3("Dec 1 1900");

  date1.Display();
  date2.Display();
  date3.Display();

  return 0;
}
