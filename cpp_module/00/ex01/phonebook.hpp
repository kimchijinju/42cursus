#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "contact.hpp"
#include "mycin.hpp"

class PhoneBook {
 public:
  PhoneBook();
  void Add();
  void Search();

 private:
  void PrintContactList();
  std::string MoreThanTenCharactersConvertDot(std::string string);
  Contact contacts_[8];
  int sequence_;
  int contact_count_;
};

#endif
