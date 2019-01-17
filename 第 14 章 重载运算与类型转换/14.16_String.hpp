#ifndef STRING_H
#define STRING_H

#include <algorithm>
#include <memory>
#include <utility>

class String {
  friend bool operator==(const String&, const String&);
  friend bool operator!=(const String&, const String&);

 public:
  String() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  String(const String&);
  String(const char*);
  ~String();
  String& operator=(const String&);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  char* begin() const { return elements; }
  char* end() const { return first_free; }

 private:
  static std::allocator<char> alloc;
  char* elements;
  char* first_free;
  char* cap;
  void chk_n_alloc();
  std::pair<char*, char*> alloc_n_copy(const char*, const char*);
  void free();
  void reallocate();
};

std::allocator<char> String::alloc;

inline void String::chk_n_alloc() {
  if (size() == capacity()) {
    reallocate();
  }
}

std::pair<char*, char*> String::alloc_n_copy(const char* b, const char* e) {
  auto data = alloc.allocate(e - b);
  return {data, std::uninitialized_copy(b, e, data)};
}

void String::free() {
  if (elements) {
    std::for_each(elements, first_free, [](char& c) { alloc.destroy(&c); });
    alloc.deallocate(elements, cap - elements);
  }
}

void String::reallocate() {
  auto newcapacity = size() ? 2 * size() : 1;
  auto newdata = alloc.allocate(newcapacity);
  auto dest = newdata;
  auto elem = elements;
  for (size_t i = 0; i != size(); ++i) {
    alloc.construct(dest++, std::move(*elem++));
  }
  free();
  elements = newdata;
  first_free = dest;
  cap = elements + newcapacity;
}

String::String(const String& s) {
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

String::String(const char* str) {
  auto p = str;
  while (p && *p++ != '\0')
    ;  // 空语句
  auto newdata = alloc_n_copy(str, p);
  elements = newdata.first;
  first_free = cap = newdata.second;
}

String::~String() { free(); }

String& String::operator=(const String& rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

bool operator==(const String& lhs, const String& rhs) {
  return lhs.elements == rhs.elements && lhs.first_free == rhs.first_free &&
         lhs.cap == rhs.cap;
}

bool operator!=(const String& lhs, const String& rhs) { return !(lhs == rhs); }

#endif
