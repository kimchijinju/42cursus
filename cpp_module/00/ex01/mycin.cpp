#include "mycin.hpp"

void ft_cin::getline(std::string &str)
{
	std::cin.clear();
	clearerr(stdin);
	std::getline(std::cin,str);
}
