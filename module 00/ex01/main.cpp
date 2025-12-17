#include <iostream>
#include <string>
#include <cctype>

int main(void)
{
	std::string action;
	std::string EXIT = "EXIT";


	do
	{
		std::cout << "Enter with one option: ADD, SEARCH or EXIT" << std::endl;
		getline(std::cin, action);		

		if (action == "ADD")
		;
		else if (action == "SEARCH")
		;
		else if (action == "EXIT")
		;

	} while (action != EXIT);
	
	return (0);
}