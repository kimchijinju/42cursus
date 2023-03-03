//
// Created by Hanbin Kim on 3/2/23.
//

#ifndef EX02__ROBOTOMYREQUESTFORM_HPP_
#define EX02__ROBOTOMYREQUESTFORM_HPP_

#include <string>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
 public:
  RobotomyRequestForm(std::string const &name);
  virtual ~RobotomyRequestForm();
  RobotomyRequestForm(RobotomyRequestForm const &robotomyRequestForm);

  virtual void execute(Bureaucrat const &executor) const throw(GradeTooLowException, NotSignedExecption);

 private: // not use
  RobotomyRequestForm();
  RobotomyRequestForm &operator= (RobotomyRequestForm const &robotomyRequestForm);

};

#endif //EX02__ROBOTOMYREQUESTFORM_HPP_
