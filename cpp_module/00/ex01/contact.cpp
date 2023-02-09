#include <iostream>
#include <string>
#include "contact.hpp"

Contact::Contact()
{

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

const std::string &Contact::first_name() const
{
	return first_name_;
}

const std::string &Contact::last_name() const
{
	return last_name_;
}


const std::string &Contact::nick_name() const
{
	return nick_name_;
}
const std::string &Contact::phone_number() const
{
	return phone_number_;
}
const std::string &Contact::darkest_secret() const
{
	return darkest_secret_;
}
