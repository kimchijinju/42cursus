//
// Created by Hanbin Kim on 3/1/23.
//

#ifndef INC_05_EX01_FORM_HPP_
#define INC_05_EX01_FORM_HPP_

#include <string>

class Bureaucrat;

class Form {
 public:
  Form(const std::string &name, const unsigned int signable_grade, const unsigned int executable_grade);
  ~Form();
  Form(const Form &form);

  void beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException);
  const std::string &getName() const;
  bool getSigned() const;
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

 private:
  const std::string name_;
  bool signed_;
  const unsigned int signable_grade_;
  const unsigned int executable_grade_;

 private: // not use
  Form();
  Form &operator=(const Form &form);
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif //INC_05_EX01_FORM_HPP_
