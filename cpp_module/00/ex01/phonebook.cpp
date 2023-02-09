#include "phonebook.hpp"

PhoneBook::PhoneBook()
{
	sequence_ = 0;
	contact_count_ = 0;
}

bool is_empty_input(std::string str)
{
	bool flag;

	for (int i = 0; i < str.length(); ++i)
	{
	}

}

void PhoneBook::Add() {

  std::string first_name, last_name, nick_name, phone_number, darkest_secret;

  std::cout << "\nEnter a new Contact..\n";

  std::cout << "first name : ";
  ft_cin::getline(first_name);

  std::cout << "last name : ";
  ft_cin::getline(last_name);

  std::cout << "nick name : ";
  ft_cin::getline(nick_name);

  std::cout << "phone number : ";
  ft_cin::getline(phone_number);

  std::cout << "darkest secret : ";
  ft_cin::getline(darkest_secret);

  std::cout << "\nsuccess!!!\n\n";

  contacts_[sequence_++] = Contact(
		  first_name,
		  last_name,
		  nick_name,
		  phone_number,
		  darkest_secret);

  if (sequence_ >= 8)
    sequence_ = 0;
  if (contact_count_ < 8)
	contact_count_ += 1;
}

void PhoneBook::Search() {
  std::string input;
  int index;

  PrintContactList();

  while (true) {
    std::cout << "\ntake index (0 ~ 7) : ";
    ft_cin::getline(input);
    if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
      break;
  }

  index = std::stoi(input);

  if (contact_count_ <= index) {
    std::cout << "\nPlease enter the correct input.\n";
    return;
  }

  std::cout << "\nfirst name : " << contacts_[index].first_name() << '\n'
            << "last name : " << contacts_[index].last_name() << '\n'
            << "nick name : " << contacts_[index].nick_name() << '\n'
            << "phone number : " << contacts_[index].phone_number() << '\n'
            << "darkest secret : " << contacts_[index].darkest_secret() << "\n\n";
}

void PhoneBook::PrintContactList() {
  std::cout << std::setw(49) << "contact list\n";

  for (int i = 0; i < contact_count_; ++i) {
    Contact contact = contacts_[i];
    std::cout << std::setw(10) << i << " | "
              << std::setw(10) << MoreThanTenCharactersConvertDot(contact.first_name()) << " | "
              << std::setw(10) << MoreThanTenCharactersConvertDot(contact.last_name()) << " | "
              << std::setw(10) << MoreThanTenCharactersConvertDot(contact.nick_name()) << '\n';
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
