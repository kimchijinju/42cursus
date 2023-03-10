//
// Created by Hanbin Kim on 3/9/23.
//

#ifndef INC_06_EX02_A_HPP_
#define INC_06_EX02_A_HPP_

#include "Base.hpp"

class A : public Base {
 public:
  A();
  ~A();
  char getType() const;

 private:
  char type;

 private: // not use
  A(const A &a);
  A &operator=(const A &a);

};

#endif //INC_06_EX02_A_HPP_
