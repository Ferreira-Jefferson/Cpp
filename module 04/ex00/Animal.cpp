#include "Animal.hpp"

Animal::Animal(void) {}

Animal::Animal(const Animal& other) {
	*this = other;
}

Animal& Animal::operator=(const Animal& other) {
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

Animal::~Animal(void) {}

std::string Animal::getType(void) const {
	return (type);
}

void Animal::makeSound(void) const {
	std::cout << "Default sound" << std::endl;
}