#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) {
	std::cout << "Default constructor called WrongAnimal" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) {
	std::cout << "Copy constructor called WrongAnimal" << std::endl;
	*this = other;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& other) {
	std::cout << "Copy assignment operator called WrongAnimal" << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "Destructor called WrongAnimal" << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return (type);
}

void WrongAnimal::makeSound(void) const {
	std::cout << "WrongAnimal default sound" << std::endl;
}
