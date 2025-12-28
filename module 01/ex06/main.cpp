#include <iostream>
#include "Harl.hpp"

int main(int argc, char *argv[]) {

	if (argc < 2 || argc > 2)
	{
		std::cout << "Expected: ./replace <level>" << std::endl;
		return (0);
	}
	if (!std::string(argv[1]).length())
		return (0);

	Harl harl = Harl();
	harl.complain(argv[1]);

	return (0);
}