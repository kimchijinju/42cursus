#include <iostream>

static void inputToUpper(char *string)
{
	for (int i = 0; string[i]; ++i)
		string[i] = std::toupper(string[i]);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
		return 0;
	}
	for (int i = 1; i < argc; ++i)
	{
		inputToUpper(argv[i]);
		std::cout << argv[i];
	}
	std::cout << '\n';
}
