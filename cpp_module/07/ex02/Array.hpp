//
// Created by Hanbin Kim on 3/16/23.
//

#ifndef EX02__ARRAY_HPP_
#define EX02__ARRAY_HPP_

#include <stdexcept>

template<typename T>
class Array {
 public:
  Array() : value_(new T[0]), size_(0) {}

  Array(unsigned int n) : value_(new T[n]), size_(n) {}

  Array(const Array &array) : value_(new T[array.size_]), size_(array.size_) {
    for (unsigned int i = 0; i < size_; ++i) {
      value_[i] = array.value_[i];
    }
  }

  Array &operator=(const Array &array) {
    if (this == &array) {
      return *this;
    }
    delete value_;
    size_ = array.size_;
    value_ = new T[size_];
    for (unsigned int i = 0; i < size_; ++i) {
      value_[i] = array.value_[i];
    }
    return *this;
  }

  ~Array() {
    delete value_;
  }

  unsigned int size() const {
    return size_;
  }

  T &operator[](unsigned int index) {
    if (index >= size_)
      throw std::runtime_error("Out of range");
    return value_[index];
  }

 private:
  T *value_;
  unsigned int size_;

};

#endif //EX02__ARRAY_HPP_
