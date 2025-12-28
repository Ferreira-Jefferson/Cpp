#include <iostream>
#include "Harl.hpp"

void print_message(Harl& harl, std::string level)
{
	std::cout << level << ": ";
	harl.complain(level);
	std::cout << std::endl;
}

int main(void) {
	Harl harl = Harl();

	print_message(harl, Harl::DEBUG);
	print_message(harl, Harl::INFO);
	print_message(harl, Harl::WARNING);
	print_message(harl, Harl::ERROR);

	harl.complain("INCORRECT");
	return (0);
}