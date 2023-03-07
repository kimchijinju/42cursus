//
// Created by Hanbin Kim on 2/26/23.
//

#ifndef INC_04_EX01_BRAIN_HPP_
#define INC_04_EX01_BRAIN_HPP_

#include <iostream>

class Brain {
 public:
  Brain();
  ~Brain();
  Brain(const Brain &brain);
  Brain &operator=(const Brain &brain);

 private:
  std::string ideas[100];
};

#endif //INC_04_EX01_BRAIN_HPP_
