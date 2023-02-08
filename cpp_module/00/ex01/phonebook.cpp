#include <iostream>
#include <iomanip>
#include <string>
#include "phonebook.hpp"

PhoneBook::PhoneBook() {
  for (int i = 0; i < 8; ++i)
    contacts_[i] = nullptr;
  sequence_ = 0;
}

void PhoneBook::Add(Contact *contact) {
  contacts_[sequence_++] = contact;

  if (sequence_ >= 8)
    sequence_ = 0;
}

void PhoneBook::Search() {
  std::string input;
  int index;
  Contact *contact;

  PrintContactList();

  while (true) {
    std::cout << "take index : ";
    std::getline(std::cin, input);
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
      break;
  }

  index = std::stoi(input);
  if (contacts_[index] == nullptr) {
    std::cout << "Please enter the correct input.\n";
    return;
  }
  contact = contacts_[index];
  std::cout << "\nfirst name : " << contact->first_name() << '\n'
            << "last name : " << contact->last_name() << '\n'
            << "nick name : " << contact->nick_name() << '\n'
            << "phone number : " << contact->phone_number() << '\n'
            << "darkest secret : " << contact->darkest_secret() << "\n\n";
}

void PhoneBook::PrintContactList() {
  std::cout << std::setw(49) << "contact list\n";

  for (int i = 0; i < 8; ++i) {
    Contact *contact = contacts_[i];
    if (contact == nullptr)
      continue;
    std::cout << std::setw(10) << i << " | "
              << std::setw(10) << MoreThanTenCharactersConvertDot(contact->first_name()) << " | "
              << std::setw(10) << MoreThanTenCharactersConvertDot(contact->last_name()) << " | "
              << std::setw(10) << MoreThanTenCharactersConvertDot(contact->nick_name()) << '\n';
  }
  std::cout << '\n';
}

std::string PhoneBook::MoreThanTenCharactersConvertDot(std::string string) {
  if (string.length() <= 10)
    return string;

  std::string ret;
  ret = string.substr(0, 10);
  ret[9] = '.';
  return ret;
}
