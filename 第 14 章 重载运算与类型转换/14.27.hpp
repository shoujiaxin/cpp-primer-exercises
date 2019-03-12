#ifndef STRBLOB_H
#define STRBLOB_H

#include <initializer_list>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

class StrBlobPtr;

class StrBlob {
  friend class StrBlobPtr;
  friend bool operator==(const StrBlob &, const StrBlob &);
  friend bool operator!=(const StrBlob &, const StrBlob &);
  friend bool operator<(const StrBlob &, const StrBlob &);

 public:
  using size_type = std::vector<std::string>::size_type;
  StrBlob();
  StrBlob(std::initializer_list<std::string> il);
  size_type size() const { return data->size(); }
  bool empty() const { return data->empty(); }
  void push_back(const std::string &t) { data->push_back(t); }
  void pop_back();
  std::string &front();
  const std::string &front() const;
  std::string &back();
  const std::string &back() const;
  StrBlobPtr begin();
  StrBlobPtr end();

  std::string &operator[](std::size_t n) { return (*data)[n]; }
  const std::string &operator[](std::size_t n) const { return (*data)[n]; }

 private:
  std::shared_ptr<std::vector<std::string>> data;
  void check(size_type i, const std::string &msg) const;
};

class StrBlobPtr {
  friend bool operator==(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator!=(const StrBlobPtr &, const StrBlobPtr &);
  friend bool operator<(const StrBlobPtr &, const StrBlobPtr &);

 public:
  StrBlobPtr() : curr(0) {}
  StrBlobPtr(StrBlob &a, size_t sz = 0) : wptr(a.data), curr(sz) {}
  std::string &deref() const;
  StrBlobPtr &incr();

  std::string &operator[](std::size_t n) { return (*(wptr.lock()))[n]; }
  const std::string &operator[](std::size_t n) const {
    return (*(wptr.lock()))[n];
  }

  StrBlobPtr &operator++();  // 前置运算符
  StrBlobPtr &operator--();
  StrBlobPtr operator++(int);  // 后置运算符
  StrBlobPtr operator--(int);

 private:
  std::weak_ptr<std::vector<std::string>> wptr;
  std::size_t curr;
  std::shared_ptr<std::vector<std::string>> check(std::size_t i,
                                                  const std::string &msg) const;
};

StrBlob::StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}

StrBlob::StrBlob(std::initializer_list<std::string> il)
    : data(std::make_shared<std::vector<std::string>>(il)) {}

void StrBlob::check(size_type i, const std::string &msg) const {
  if (i >= data->size()) {
    throw std::out_of_range(msg);
  }
}

void StrBlob::pop_back() {
  check(0, "pop_back on empty StrBlob");
  data->pop_back();
}

std::string &StrBlob::front() {
  check(0, "front on empty StrBlob");
  return data->front();
}

const std::string &StrBlob::front() const {
  check(0, "front on empty StrBlob");
  return data->front();
}

std::string &StrBlob::back() {
  check(0, "back on empty StrBlob");
  return data->back();
}

const std::string &StrBlob::back() const {
  check(0, "back on empty StrBlob");
  return data->back();
}

StrBlobPtr StrBlob::begin() { return StrBlobPtr(*this); }

StrBlobPtr StrBlob::end() { return StrBlobPtr(*this, data->size()); }

std::shared_ptr<std::vector<std::string>> StrBlobPtr::check(
    std::size_t i, const std::string &msg) const {
  auto ret = wptr.lock();
  if (!ret) {
    throw std::runtime_error("unbound StrBlobPtr");
  }
  if (i >= ret->size()) {
    throw std::out_of_range("msg");
  }
  return ret;
}

std::string &StrBlobPtr::deref() const {
  auto p = check(curr, "deference past end");
  return (*p)[curr];
}

StrBlobPtr &StrBlobPtr::incr() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr &StrBlobPtr::operator++() {
  check(curr, "increment past end of StrBlobPtr");
  ++curr;
  return *this;
}

StrBlobPtr &StrBlobPtr::operator--() {
  --curr;
  check(curr, "decrement past begin of StrBlobPtr");
  return *this;
}

StrBlobPtr StrBlobPtr::operator++(int) {
  StrBlobPtr ret = *this;
  ++*this;
  return ret;
}

StrBlobPtr StrBlobPtr::operator--(int) {
  StrBlobPtr ret = *this;
  --*this;
  return ret;
}

bool operator==(const StrBlob &lhs, const StrBlob &rhs) {
  return *lhs.data == *rhs.data;
}

bool operator!=(const StrBlob &lhs, const StrBlob &rhs) {
  return !(lhs == rhs);
}

bool operator<(const StrBlob &lhs, const StrBlob &rhs) {
  return *lhs.data < *rhs.data;
}

bool operator==(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.wptr.lock() == rhs.wptr.lock() && lhs.curr == rhs.curr;
}

bool operator!=(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return !(lhs == rhs);
}

bool operator<(const StrBlobPtr &lhs, const StrBlobPtr &rhs) {
  return lhs.wptr.lock() < rhs.wptr.lock() && lhs.curr < rhs.curr;
}

#endif
