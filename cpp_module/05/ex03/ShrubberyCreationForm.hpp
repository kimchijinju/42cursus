#ifndef EX02__SHRUBBERYCREATIONFORM_HPP_
#define EX02__SHRUBBERYCREATIONFORM_HPP_

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
 public:
  ShrubberyCreationForm(const std::string &name);
  virtual ~ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &shrubberyCreationForm);

  virtual void execute(const Bureaucrat &executor) const throw(GradeTooLowException, NotSignedExecption);

 private: // not use
  ShrubberyCreationForm();
  ShrubberyCreationForm &operator= (const ShrubberyCreationForm &shrubberyCreationForm);
};

#endif //EX02__SHRUBBERYCREATIONFORM_HPP_
