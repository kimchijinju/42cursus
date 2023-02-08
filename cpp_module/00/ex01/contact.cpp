#include <iostream>
#include <string>
#include "contact.hpp"

Contact::Contact() {
  std::cout << "\nEnter a new Contact..\n";

  std::cout << "first name : ";
  std::getline(std::cin, first_name_);

  std::cout << "last name : ";
  std::getline(std::cin, last_name_);

  std::cout << "nick name : ";
  std::getline(std::cin, nick_name_);

  std::cout << "phone number : ";
  std::getline(std::cin, phone_number_);

  std::cout << "darkest secret : ";
  std::getline(std::cin, darkest_secret_);

  std::cout << "\nsuccess!!!\n\n";
}

Contact::Contact(const std::string &first_name,
                 const std::string &last_name,
                 const std::string &nick_name,
                 const std::string &phone_number,
                 const std::string &darkest_secret)
    : first_name_(first_name),
      last_name_(last_name),
      nick_name_(nick_name),
      phone_number_(phone_number),
      darkest_secret_(darkest_secret) {}
