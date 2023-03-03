#include <iostream>
#include "Bureaucrat.hpp"

int main() {
  try {
    Bureaucrat hanbkim("hanbkim", 5);
    std::cout << hanbkim << '\n';

//    for (int i = 0; i < 5; ++i) {
//      hanbkim.increaseGrade();
//      std::cout << hanbkim;
//    }

    Bureaucrat joushin("joushin", 151);
    std::cout << joushin;

  } catch (std::exception &e) {
    std::cout << e.what() << '\n';
  }

}
