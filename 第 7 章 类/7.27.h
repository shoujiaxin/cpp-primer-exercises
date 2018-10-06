#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

class Screen {
 public:
  using pos = std::string::size_type;

  Screen() = default;
  Screen(pos ht, pos wd) : height(ht), width(wd), contents(ht * wd, ' ') {}
  Screen(pos ht, pos wd, char c)
      : height(ht), width(wd), contents(ht * wd, c) {}

  char get() const { return contents[cursor]; }
  char get(pos r, pos c) const { return contents[r * width + c]; }
  Screen &move(pos r, pos c) {
    cursor = r * width + c;
    return *this;
  }
  Screen &set(char c) {
    contents[cursor] = c;
    return *this;
  }
  Screen &set(pos r, pos c, char ch) {
    contents[r * width + c] = ch;
    return *this;
  }
  const Screen &display(std::ostream &os) const {
    do_display(os);
    return *this;
  }
  Screen &display(std::ostream &os) {
    do_display(os);
    return *this;
  }

 private:
  pos cursor = 0;
  pos height = 0;
  pos width = 0;
  std::string contents;

  void do_display(std::ostream &os) const { os << contents; }
};

#endif
