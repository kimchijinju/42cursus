#include "FtCin.hpp"
#include "PhoneBook.hpp"

void UsePhoneBook() {
  std::string command;
  PhoneBook phone_book;

  while (true) {
    std::cout << "PHONE BOOK MANUAL : TAKE ONE COMMAND...\n[ADD] [SEARCH] [EXIT]\n\n";
	FtCin::getline(command);

	if (command == "ADD")
		phone_book.Add();
	else if (command == "SEARCH")
		phone_book.Search();
	else if (command == "EXIT")
		exit(0);
  }
}

int main() {

  std::cout << std::right;
  UsePhoneBook();
}
