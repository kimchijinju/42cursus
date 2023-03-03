//
// Created by Hanbin Kim on 3/1/23.
//

#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string &name,
             const unsigned int signable_grade,
             const unsigned int executable_grade)
    : name_(name), signed_(false), signable_grade_(signable_grade), executable_grade_(executable_grade) {
  if (signable_grade_ < 1 || executable_grade_ < 1)
    throw GradeTooHighException();
  if (signable_grade_ > 150 || executable_grade_ > 150)
    throw GradeTooLowException();
}

AForm::~AForm() {

}

AForm::AForm(const AForm &form)
    : name_(form.name_),
      signed_(form.signed_),
      signable_grade_(form.signable_grade_),
      executable_grade_(form.executable_grade_) {

}

void AForm::beSigned(Bureaucrat &bureaucrat) throw(GradeTooLowException) {
  if (signable_grade_ < bureaucrat.getGrade())
    throw GradeTooLowException();
  signed_ = true;
}

void AForm::validateExecutableBureaucrat(const Bureaucrat &executor) const throw(GradeTooLowException, NotSignedExecption) {
  if (!isSigned())
    throw NotSignedExecption();
  if (executable_grade_ < executor.getGrade())
    throw GradeTooLowException();
}

const std::string &AForm::getName() const {
  return name_;
}

bool AForm::isSigned() const {
  return signed_;
}

unsigned int AForm::getSignableGrade() const {
  return signable_grade_;
}

unsigned int AForm::getExecutableGrade() const {
  return executable_grade_;
}


const char *AForm::GradeTooHighException::what() const throw() {
  return "Form: grade too high.";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "Form: grade too low.";
}

const char *AForm::NotSignedExecption::what() const throw() {
  return "Form: this form is not signed.";
}

std::ostream &operator<<(std::ostream &out, AForm const &form) {
  out << "name : " << form.getName()
      << "\nsigned : " << form.isSigned()
      << "\nsignable_grade : " << form.getSignableGrade()
      << "\nexecutable_grade : " << form.getExecutableGrade() << '\n';
  return out;
}
