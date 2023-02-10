#include "FtCin.hpp"

void FtCin::getline(std::string &str) {
	std::cin.clear();
	clearerr(stdin);
	std::getline(std::cin,str);
	if (std::cin.eof())
		exit(0);
}
