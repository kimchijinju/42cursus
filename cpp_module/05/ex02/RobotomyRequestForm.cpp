//
// Created by Hanbin Kim on 3/2/23.
//

#include <iostream>
#include <cstdlib>
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &name) : AForm(name, 72, 45) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &robotomyRequestForm)
    : AForm(robotomyRequestForm.name_, robotomyRequestForm.signable_grade_, robotomyRequestForm.executable_grade_) {}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const throw(GradeTooLowException, NotSignedExecption) {
  validateExecutableBureaucrat(executor);

  std::cout << "drilling.............\n";
  srand(time(NULL));
  if (rand() % 2 == 1) {
    std::cout << executor.getName() << " is now robot.\n";
  } else {
    std::cout << executor.getName() << " is fail robotomized.\n";
  }
}
