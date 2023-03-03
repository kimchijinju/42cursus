//
// Created by Hanbin Kim on 3/2/23.
//

#include <iostream>
#include <fstream>
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name) : AForm(name, 145, 137) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &shrubberyCreationForm) : AForm(
    shrubberyCreationForm.name_,
    shrubberyCreationForm.signable_grade_,
    shrubberyCreationForm.executable_grade_) {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const throw(GradeTooLowException, NotSignedExecption) {
  validateExecutableBureaucrat(executor);

  std::ofstream tree((getName() + "_shrubbery").c_str());
  tree << "       _-_\n"
          "    /~~   ~~\\\n"
          " /~~         ~~\\\n"
          "{               }\n"
          " \\  _-     -_  /\n"
          "   ~  \\\\ //  ~\n"
          "_- -   | | _- _\n"
          "  _ -  | |   -_\n"
          "      // \\\\\n";
}
