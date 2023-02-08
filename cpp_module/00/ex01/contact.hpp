#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
 public:
  Contact();
  Contact(const std::string &first_name,
          const std::string &last_name,
          const std::string &nick_name,
          const std::string &phone_number,
          const std::string &darkest_secret);

  const std::string &first_name() const {
    return first_name_;
  }
  const std::string &last_name() const {
    return last_name_;
  }
  const std::string &nick_name() const {
    return nick_name_;
  }
  const std::string &phone_number() const {
    return phone_number_;
  }
  const std::string &darkest_secret() const {
    return darkest_secret_;
  }

 private:
  std::string first_name_;
  std::string last_name_;
  std::string nick_name_;
  std::string phone_number_;
  std::string darkest_secret_;
};

#endif
