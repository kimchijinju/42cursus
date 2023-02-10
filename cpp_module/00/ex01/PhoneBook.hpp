#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "Contact.hpp"
#include "FtCin.hpp"

class PhoneBook {
public:
	PhoneBook();
	void Add();
	void Search();

private:
	bool IsEmptyInput(std::string str);
	bool GetInput(std::string &str);
	bool GetContact(Contact &contact);
	void PrintContactList();
	void PrintSearchResultContact(int index);
	std::string MoreThanTenCharactersConvertDot(std::string string);
	Contact contacts_[8];
	int sequence_;
	int contact_count_;
};

#endif
