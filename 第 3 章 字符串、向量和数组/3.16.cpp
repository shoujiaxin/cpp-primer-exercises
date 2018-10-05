#include <iostream>
#include <string>
#include <vector>
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main(int argc, char const *argv[]) {
  vector<int> v1;
  cout << "v1:\n";

  vector<int> v2(10);
  cout << "v2: ";
  for (auto i : v2) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> v3(10, 42);
  cout << "v3: ";
  for (auto i : v3) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> v4{10};
  cout << "v4: ";
  for (auto i : v4) {
    cout << i << ' ';
  }
  cout << endl;

  vector<int> v5{10, 42};
  cout << "v5: ";
  for (auto i : v5) {
    cout << i << ' ';
  }
  cout << endl;

  vector<string> v6{10};
  cout << "v6: ";
  for (auto i : v6) {
    cout << i << ' ';
  }
  cout << endl;

  vector<string> v7{10, "hi"};
  cout << "v7: ";
  for (auto i : v7) {
    cout << i << ' ';
  }
  cout << endl;
  return 0;
}
