#include "phonebook.hpp"

PhoneBook::PhoneBook() {
	sequence_ = 0;
	contact_count_ = 0;
}

void PhoneBook::Add() {
	Contact contact;

	if (GetContact(contact) == false)
		return ;

	contacts_[sequence_++] = contact; 

	if (sequence_ >= 8)
		sequence_ = 0;
	if (contact_count_ < 8)
		contact_count_ += 1;
}

void PhoneBook::Search() {
	std::string input;

	PrintContactList();

	while (true) {
		std::cout << "\ntake index (0 ~ 7) : ";
		ft_cin::getline(input);

		if (input.length() == 1 && input[0] >= '0' && input[0] <= '7')
			break ;
	}

	int index;

	index = std::stoi(input);
	if (contact_count_ <= index) 
	{
		std::cout << "\nPlease enter the correct input.\n";
		return ;
	}

	PrintSearchResultContact(index);
}
 
bool PhoneBook::IsEmptyInput(std::string str) {
	int	count = 0;
	int length = str.length();

	for (int i = 0; i < length; ++i) {
		if (std::isspace(str[i]))
			count += 1;
	}
	return (length == count);
}

bool PhoneBook::GetInput(std::string &str) {
	ft_cin::getline(str);
	if (IsEmptyInput(str)) {
		std::cout << "\nEmpty field can't save\n";
		return false;
	}
	return true;
}

bool PhoneBook::GetContact(Contact &contact) {
	std::string first_name, last_name, nick_name, phone_number, darkest_secret;

	std::cout << "\nEnter a new Contact..\n";

	std::cout << "first name : ";
	if (GetInput(first_name) == false)
		return false;

	std::cout << "last name : ";
	if (GetInput(last_name) == false)
		return false;

	std::cout << "nick name : ";
	if (GetInput(nick_name) == false)
		return false;

	std::cout << "phone number : ";
	if (GetInput(phone_number) == false)
		return false;

	std::cout << "darkest secret : ";
	if (GetInput(darkest_secret) == false)
		return false;

	std::cout << "\nsuccess!!!\n\n";
	contact = Contact(first_name, last_name, nick_name, phone_number, darkest_secret);
	return true;
}


void PhoneBook::PrintSearchResultContact(int index) {
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
