#include <iostream>
using std::cout;
using std::endl;

int main(int argc, char const *argv[]) {
  int ia[3][4] = {{0, 1, 2, 3}, {4, 5, 6, 7}, {8, 9, 10, 11}};
  using int_array = int[4];
  // 1
  cout << "1: " << endl;
  for (int_array &row : ia) {
    for (int col : row) {
      cout << col << ' ';
    }
  }
  cout << endl;
  // 2
  cout << "2: " << endl;
  for (size_t row = 0; row < 3; ++row) {
    for (size_t col = 0; col < 4; ++col) {
      cout << ia[row][col] << " ";
    }
  }
  cout << endl;
  // 3
  cout << "3: " << endl;
  for (int_array *row = ia; row != ia + 3; ++row) {
    for (int *col = *row; col != *row + 4; ++col) {
      cout << *col << ' ';
    }
  }
  cout << endl;
  return 0;
}
