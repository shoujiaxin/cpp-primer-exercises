#ifndef DATE_H
#define DATE_H

#include <array>
#include <iostream>
#include <string>

class Date {
 public:
  Date(unsigned y, unsigned m, unsigned d) : year(y), month(m), day(d) {}
  Date(const std::string &dateStr);
  void Display() {
    std::cout << "Year: " << year << " Month: " << month << " Day: " << day
              << std::endl;
  }

 private:
  unsigned year;
  unsigned month;
  unsigned day;
};

Date::Date(const std::string &dateStr) {
  const std::string splitChar{", /"};
  year = static_cast<unsigned>(
      stoi(dateStr.substr(dateStr.find_last_of(splitChar) + 1)));

  std::string monthStr = dateStr.substr(0, dateStr.find_first_of(splitChar));
  const std::string numbers{"0123456789"};
  const std::array<std::string, 12> mons{"Jan", "Feb", "Mar", "Apr",
                                         "May", "Jun", "Jul", "Aug",
                                         "Sep", "Oct", "Nov", "Dec"};
  if (monthStr.find_first_of(numbers) == std::string::npos) {
    decltype(mons.size()) cnt = 0;
    while (cnt != mons.size()) {
      if (monthStr.find(mons.at(cnt)) != std::string::npos) {
        month = static_cast<unsigned>(cnt + 1);
      }
      ++cnt;
    }
  } else {
    month = static_cast<unsigned>(stoi(monthStr));
  }

  std::string::size_type pos = dateStr.find_first_of(splitChar);
  ++pos;
  day = static_cast<unsigned>(
      stoi(dateStr.substr(pos, dateStr.find_first_of(splitChar, pos) - pos)));
}

#endif
