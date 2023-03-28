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
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;
  typedef typename std::stack<T>::container_type::iterator iterator;

  const_iterator begin() const
  {
    return this->c.begin();
  }

  const_iterator end() const
  {
    return this->c.end();
  }

  iterator begin()
  {
    return this->c.begin();
  }

  iterator end()
  {
    return this->c.end();
  }

  MutantStack() {}
  ~MutantStack() {}
  MutantStack(const MutantStack &mutantStack) : std::stack<T>(mutantStack) {}
  MutantStack &operator=(const MutantStack &mutantStack)
  {
    if (this == &mutantStack)
    {
      return *this;
    }

    std::stack<T>::operator=(mutantStack);
    return *this;
  }
};

#endif //INC_08_EX02_MUTANTSTACK_HPP_
