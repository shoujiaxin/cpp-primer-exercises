#ifndef STRBLOBPTRPTR_H
#define STRBLOBPTRPTR_H

#include "14.26_StrBlob.hpp"

class StrBlobPtrPtr {
 public:
  StrBlobPtrPtr() = default;
  StrBlobPtrPtr(StrBlobPtr sbp) : ptr(std::make_shared<StrBlobPtr>(sbp)) {}

  // 解引用运算符
  StrBlobPtr& operator*() const;
  // 箭头运算符
  StrBlobPtr* operator->() const;

 private:
  std::shared_ptr<StrBlobPtr> ptr;
};

StrBlobPtr& StrBlobPtrPtr::operator*() const { return *ptr; }

StrBlobPtr* StrBlobPtrPtr::operator->() const { return &this->operator*(); }

#endif
