#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
 public:
  Contact(const std::string &first_name,
          const std::string &last_name,
          const std::string &nick_name,
          const std::string &phone_number,
          const std::string &darkest_secret);
  
  Contact();
  const std::string &first_name() const;
  const std::string &last_name() const;
  const std::string &nick_name() const;
  const std::string &phone_number() const;
  const std::string &darkest_secret() const;

 private:
  std::string first_name_;
  std::string last_name_;
  std::string nick_name_;
  std::string phone_number_;
  std::string darkest_secret_;
};

#endif
