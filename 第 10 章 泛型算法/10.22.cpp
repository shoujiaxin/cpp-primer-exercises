#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std::placeholders;

bool isNotLongerThan(const std::string &str,
                     const std::string::size_type length) {
  return str.size() <= length;
}

int main(int argc, char const *argv[]) {
  std::vector<std::string> words{"cpp", "primer", "fifth", "edition"};
  std::cout << count_if(words.begin(), words.end(),
                        std::bind(isNotLongerThan, _1, 6))
            << std::endl;
  return 0;
}
