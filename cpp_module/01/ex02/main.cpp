#include <iostream>

int main() {
  std::string str = "HI THIS IS BRAIN";
  std::string *stringPtr = &str;
  std::string &stringREF = str;

  std::cout << "string address : " << &str << "\n";
  std::cout << "string ptr address : " << stringPtr << "\n";
  std::cout << "string reference address : " << &stringREF << "\n";

  std::cout << "string value : " << str << "\n";
  std::cout << "string ptr value : " << *stringPtr << "\n";
  std::cout << "string reference value : " << stringREF << "\n";
}