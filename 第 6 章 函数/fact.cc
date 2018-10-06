#include "Chapter6.h"

unsigned fact(unsigned val) {
  unsigned result = 1;
  while (val > 1) {
    result *= val;
    --val;
  }
  return result;
}
