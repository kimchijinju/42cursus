//
// Created by Hanbin Kim on 3/2/23.
//

#ifndef EX02__PRESIDENTIALPARDONFORM_HPP_
#define EX02__PRESIDENTIALPARDONFORM_HPP_

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
 public:
  PresidentialPardonForm(std::string const &name);
  virtual ~PresidentialPardonForm();
  PresidentialPardonForm(PresidentialPardonForm const &presidentialPardonForm);

  virtual void execute(Bureaucrat const &executor) const throw(GradeTooLowException, NotSignedExecption);

 private: // not use
  PresidentialPardonForm();
  PresidentialPardonForm &operator= (PresidentialPardonForm const &presidentialPardonForm);
};

#endif //EX02__PRESIDENTIALPARDONFORM_HPP_
