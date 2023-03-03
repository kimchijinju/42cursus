//
// Created by Hanbin Kim on 3/1/23.
//

#ifndef INC_05_EX01_FORM_HPP_
#define INC_05_EX01_FORM_HPP_

#include <string>

class Bureaucrat;

class AForm {
 public:
  AForm(const std::string &name, const unsigned int signable_grade, const unsigned int executable_grade);
  virtual ~AForm();
  AForm(const AForm &form);

  void beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException);
  virtual void execute(Bureaucrat const &executor) const throw(GradeTooLowException, NotSignedExecption) = 0;

  const std::string &getName() const;
  bool isSigned() const;
  unsigned int getSignableGrade() const;
  unsigned int getExecutableGrade() const;

  class GradeTooHighException : public std::exception {
   public:
    const char *what() const throw();
  };

  class GradeTooLowException : public std::exception {
   public:
    const char *what() const throw();
  };

  class NotSignedExecption : public std::exception {
   public:
    const char * what() const throw();
  };

 protected:
  void validateExecutableBureaucrat(const Bureaucrat &executor) const throw(GradeTooLowException, NotSignedExecption);
  const std::string name_;
  bool signed_;
  const unsigned int signable_grade_;
  const unsigned int executable_grade_;


 private: // not use
  AForm();
  AForm &operator=(const AForm &form);
};

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif //INC_05_EX01_FORM_HPP_
