//
// Created by Hanbin Kim on 3/9/23.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::Base() {

}

Base::~Base() {

}

Base *Base::generate(void) {
  srand(time(NULL));
  int generate = rand() % 3;

  std::cout << "gen\n";
  switch (generate) {
    case 0 : return new A();
    case 1 : return new B();
    case 2 : return new C();
  }
  return NULL;
}

void Base::identify(Base *p) {
  A *a = dynamic_cast<A *>(p);
  if (a != NULL)
    std::cout << "A\n";
  B *b = dynamic_cast<B *>(p);
  if (b != NULL)
    std::cout << "B\n";
  C *c = dynamic_cast<C *>(p);
  if (c != NULL)
    std::cout << "C\n";
}

void Base::identify(Base &p) {
  (void) p;
//  A& a = dynamic_cast<A&>(p);
//  B& b = dynamic_cast<B&>(p);
//  C& c = dynamic_cast<C&>(p);

}
