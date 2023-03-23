//
// Created by Hanbin Kim on 3/23/23.
//

#ifndef INC_08_EX02_MUTANTSTACK_HPP_
#define INC_08_EX02_MUTANTSTACK_HPP_

#include <algorithm>
#include <stack>

template<typename T>
class MutantStack : public std::stack<T>
{
 public:
  class iterator : public std::iterator<std::input_iterator_tag, T>
  {
   public:
    iterator(const iterator &iterator) : ptr_(iterator.ptr_) {}
    iterator(T *ptr) : ptr_(ptr) {}
    iterator &operator++()
    {
      ++ptr_;
      return *this;
    }
    iterator operator++(int)
    {
      iterator ret = *this;
      ++ptr_;
      return ret;
    }
    iterator &operator--()
    {
      --ptr_;
      return *this;
    }
    iterator operator--(int)
    {
      iterator ret = *this;
      --ptr_;
      return ret;
    }
    bool operator==(const iterator &rhs) const
    {
      return ptr_ == rhs.ptr_;
    }
    bool operator!=(const iterator &rhs) const
    {
      return ptr_ != rhs.ptr_;
    }
    T &operator*() { return *ptr_; }
    ~iterator() {}
   private:
    T *ptr_;
    // not use
    iterator();
    iterator &operator=(const iterator &iterator);
  };

  iterator &begin()
  {
    return std::stack<T>::container_type.begin();
  }

  iterator &end()
  {
    return std::stack<T>::container_type::end();
  };
  MutantStack() {}
  ~MutantStack() {}

 private:
  MutantStack(const MutantStack &mutantStack);
  MutantStack &operator= (const MutantStack &mutantStack);


};

#endif //INC_08_EX02_MUTANTSTACK_HPP_
