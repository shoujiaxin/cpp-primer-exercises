#ifndef STRVEC_H
#define STRVEC_H

#include <initializer_list>
#include <memory>
#include <string>
#include <utility>

class StrVec {
  friend bool operator==(const StrVec &, const StrVec &);
  friend bool operator!=(const StrVec &, const StrVec &);
  friend bool operator<(const StrVec &, const StrVec &);

 public:
  StrVec() : elements(nullptr), first_free(nullptr), cap(nullptr) {}
  StrVec(const StrVec &);
  StrVec(const std::initializer_list<std::string> &);
  ~StrVec();
  StrVec &operator=(const StrVec &);
  void push_back(const std::string &);
  size_t size() const { return first_free - elements; }
  size_t capacity() const { return cap - elements; }
  std::string *begin() const { return elements; }
  std::string *end() const { return first_free; }

  std::string &operator[](std::size_t n) { return elements[n]; }
  const std::string &operator[](std::size_t n) const { return elements[n]; }

 private:
  static std::allocator<std::string> alloc;
  std::string *elements;    // 指向数组首元素的指针
  std::string *first_free;  // 指向数组第一个空闲元素的指针
  std::string *cap;         // 指向数组尾后位置的指针
  void chk_n_alloc();
  std::pair<std::string *, std::string *> alloc_n_copy(const std::string *,
                                                       const std::string *);
  void free();
  void reallocate();
};

std::allocator<std::string> StrVec::alloc;

inline void StrVec::chk_n_alloc() {
  if (size() == capacity()) {
    reallocate();
  }
}

std::pair<std::string *, std::string *> StrVec::alloc_n_copy(
    const std::string *b, const std::string *e) {
  auto data = alloc.allocate(e - b);
  return {data, uninitialized_copy(b, e, data)};
}

void StrVec::free() {
  if (elements) {
    for (auto p = first_free; p != elements;) {
      alloc.destroy(--p);
    }
    alloc.deallocate(elements, cap - elements);
  }
}

void StrVec::reallocate() {
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

StrVec::StrVec(const StrVec &s) {
  auto newdata = alloc_n_copy(s.begin(), s.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec::StrVec(const std::initializer_list<std::string> &il) {
  auto newdata = alloc_n_copy(il.begin(), il.end());
  elements = newdata.first;
  first_free = cap = newdata.second;
}

StrVec::~StrVec() { free(); }

StrVec &StrVec::operator=(const StrVec &rhs) {
  auto data = alloc_n_copy(rhs.begin(), rhs.end());
  free();
  elements = data.first;
  first_free = cap = data.second;
  return *this;
}

void StrVec::push_back(const std::string &s) {
  chk_n_alloc();
  alloc.construct(first_free++, s);
}

bool operator==(const StrVec &lhs, const StrVec &rhs) {
  return lhs.elements == rhs.elements && lhs.first_free == rhs.first_free &&
         lhs.cap == rhs.cap;
}

bool operator!=(const StrVec &lhs, const StrVec &rhs) { return !(lhs == rhs); }

bool operator<(const StrVec &lhs, const StrVec &rhs) {
  return lhs.elements < rhs.elements && lhs.first_free < rhs.first_free &&
         lhs.cap < rhs.cap;
}

#endif
