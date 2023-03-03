#ifndef INC_05_EX00_BUREAUCRAT_HPP_
#define INC_05_EX00_BUREAUCRAT_HPP_

#include <string>

class Form;

class Bureaucrat {
 public:
  Bureaucrat(const std::string &name, unsigned int grade);
  ~Bureaucrat();
  Bureaucrat(const Bureaucrat &bureaucrat);

  void signForm(Form &form);
  void increaseGrade() throw(GradeTooHighException);
  void decreaseGrade() throw(GradeTooLowException);
  const std::string &getName() const;
  unsigned int getGrade() const;

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
  unsigned int grade_;

 private: // not use
  Bureaucrat();
  Bureaucrat &operator=(const Bureaucrat &bureaucrat);
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif //INC_05_EX00_BUREAUCRAT_HPP_
