//
// Created by Hanbin Kim on 3/9/23.
//

#ifndef INC_06_EX02_B_HPP_
#define INC_06_EX02_B_HPP_

#include "Base.hpp"

class B : public Base {
 public:
  B();
  ~B();

 private: // not use
  B(const B &b);
  B &operator= (const B &b);

};

#endif //INC_06_EX02_B_HPP_
