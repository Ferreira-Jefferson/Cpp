#include <iostream>
#include <string>
#include <cctype>

#include "PhoneBook.hpp"

int main(void)
{
	std::string action;
	std::string EXIT = "EXIT";
	PhoneBook pb = PhoneBook();
	
	do
	{
		std::cout << "Enter with one option: ADD, SEARCH or EXIT" << std::endl;
		if (!getline(std::cin, action))
			break ;
		
		if (action == "ADD")
			pb.add();
		else if (action == "SEARCH")
			pb.search();
	} while (action != EXIT);
	
	return (0);
}