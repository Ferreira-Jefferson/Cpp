#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	std::cout << "Default constructor called WrongCat" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& other): WrongAnimal(other) {
	std::cout << "Copy constructor called WrongCat" << std::endl;
	*this = other;
}

WrongCat& WrongCat::operator=(const WrongCat& other) {
	std::cout << "Copy assignment operator called WrongCat" << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

WrongCat::~WrongCat(void) {
	std::cout << "Destructor called WrongCat" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "WrongCat Miaaaauuuuuuuuuuu" << std::endl;
}
