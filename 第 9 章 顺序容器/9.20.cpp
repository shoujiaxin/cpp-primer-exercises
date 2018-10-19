#include <deque>
#include <list>

int main(int argc, char const *argv[]) {
  std::list<int> iList = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
  std::deque<int> oddDeque;   // 奇数
  std::deque<int> evenDeque;  // 偶数

  for (auto val : iList) {
    if (val % 2) {
      oddDeque.push_back(val);
    } else {
      evenDeque.push_back(val);
    }
  }
  return 0;
}
