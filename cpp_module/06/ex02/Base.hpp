//
// Created by Hanbin Kim on 3/9/23.
//

#ifndef INC_06_EX02_BASE_HPP_
#define INC_06_EX02_BASE_HPP_

class Base {
 public:
  Base();
  virtual ~Base();

  Base * generate(void);
  void identify(Base* p);
  void identify(Base& p);

 private: // not use
  Base(const Base &base);
  Base &operator= (const Base &base);


};

#endif //INC_06_EX02_BASE_HPP_
