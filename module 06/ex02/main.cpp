#include "Base.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(void)
{
	std::srand(std::time(NULL));

	for (int i = 0; i < 10; i++)
	{
		Base* obj = generate();
		std::cout << "pointer: ";
		identify(obj);
		std::cout << "reference: ";
		identify(*obj);

		std::cout << std::endl;
		delete obj;
	}
	return 0;
}
