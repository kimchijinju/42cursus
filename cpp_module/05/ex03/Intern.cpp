//
// Created by Hanbin Kim on 3/3/23.
//

#include <iostream>
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() : memorizeForm() {
  memorizeForm[0] = "shrubbery creation";
  makeFormFunction[0] = &Intern::makeShrubberyCreationForm;

  memorizeForm[1] = "robotomy request";
  makeFormFunction[1] = &Intern::makeRobotomyRequestForm;

  memorizeForm[2] = "presidential pardon";
  makeFormFunction[2] = &Intern::makePresidentialPardonForm;
}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName, std::string const &formTarget) {
  for (unsigned int i = 0; i < MAX_MEMORIZE; ++i) {
    if (memorizeForm[i] == formName) {
      std::cout << "Intern creates " <<  formTarget << '\n';
      return (this->*makeFormFunction[i])(formTarget);
    }
  }
  std::cout << formName << " does not exist." <<  '\n';
  return NULL;
}

AForm *Intern::makeShrubberyCreationForm(std::string const &target) {
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeRobotomyRequestForm(std::string const &target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardonForm(std::string const &target) {
  return new PresidentialPardonForm(target);
}
