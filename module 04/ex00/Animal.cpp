#include "Animal.hpp"

Animal::Animal(void) {
	std::cout << "Default constructor called Animal" << std::endl;
}

Animal::Animal(const Animal& other) {
	std::cout << "Copy constructor called Animal" << std::endl;
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	std::cout << "Copy assignment operator called Animal" << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

Animal::~Animal(void) {
	std::cout << "Destructor called Animal" << std::endl;
}

std::string Animal::getType(void) const {
	return (type);
}

void Animal::makeSound(void) const {
	std::cout << "Default sound" << std::endl;
}