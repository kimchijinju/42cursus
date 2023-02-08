#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"

class PhoneBook {
 public:
  PhoneBook();
  void Add(Contact *contact);
  void Search();

 private:
  void PrintContactList();
  std::string MoreThanTenCharactersConvertDot(std::string string);
  Contact *contacts_[8];
  int sequence_;
};

#endif
