//
// Created by Hanbin Kim on 3/2/23.
//

#include <iostream>
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &name) : AForm(name, 25, 5) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm) : AForm(
    presidentialPardonForm.name_,
    presidentialPardonForm.signable_grade_,
    presidentialPardonForm.executable_grade_) {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const throw(GradeTooLowException, NotSignedExecption) {
  validateExecutableBureaucrat(executor);

  std::cout << executor.getName() << " has been pardoned by Zaphod Beeblebrox.\n";
}
