//
// Created by Hanbin Kim on 3/9/23.
//

#ifndef INC_06_EX02_C_HPP_
#define INC_06_EX02_C_HPP_

#include "Base.hpp"

class C : public Base {
 public:
  C();
  ~C();
  char getType() const;

 private:
  char type;

 private: // not use
  C(const C &c);
  C &operator= (const C &c);


};

#endif //INC_06_EX02_C_HPP_
