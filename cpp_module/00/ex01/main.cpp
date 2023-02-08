#include <iostream>
#include <string>
#include "phonebook.hpp"

void usePhoneBook(PhoneBook& phone_book, const std::string& command) {
  if (command == "ADD")
    phone_book.Add(new Contact());
  else if (command == "SEARCH")
    phone_book.Search();
  else if (command == "EXIT")
    exit(0);
}

int main() {
  PhoneBook phone_book;
  std::string command;

  std::cout << std::right;
  phone_book.Add(new Contact("1", "1", "1," ,"1", "1"));
  while (true) {
    std::cout << "PHONE BOOK MANUAL : TAKE ONE COMMAND...\n[ADD] [SEARCH] [EXIT]\n\n";
    std::getline(std::cin, command);
    usePhoneBook(phone_book, command);
  }
}