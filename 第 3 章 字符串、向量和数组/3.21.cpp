#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[]) {
  vector<int> v1;
  cout << "v1: ";
  for (auto it1 = v1.begin(); it1 != v1.end(); ++it1) {
    cout << *it1 << ' ';
  }
  cout << endl;

  vector<int> v2(10);
  cout << "v2: ";
  for (auto it2 = v2.begin(); it2 != v2.end(); ++it2) {
    cout << *it2 << ' ';
  }
  cout << endl;

  vector<int> v3(10, 42);
  cout << "v3: ";
  for (auto it3 = v3.begin(); it3 != v3.end(); ++it3) {
    cout << *it3 << ' ';
  }
  cout << endl;

  vector<int> v4{10};
  cout << "v4: ";
  for (auto it4 = v4.begin(); it4 != v4.end(); ++it4) {
    cout << *it4 << ' ';
  }
  cout << endl;

  vector<int> v5{10, 42};
  cout << "v5: ";
  for (auto it5 = v5.begin(); it5 != v5.end(); ++it5) {
    cout << *it5 << ' ';
  }
  cout << endl;

  vector<string> v6{10};
  cout << "v6: ";
  for (auto it6 = v6.begin(); it6 != v6.end(); ++it6) {
    cout << *it6 << ' ';
  }
  cout << endl;

  vector<string> v7{10, "hi"};
  cout << "v7: ";
  for (auto it7 = v7.begin(); it7 != v7.end(); ++it7) {
    cout << *it7 << ' ';
  }
  cout << endl;
  return 0;
}
