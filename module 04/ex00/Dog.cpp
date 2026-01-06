#include "Dog.hpp"

Dog::Dog(void) {
	type = "Dog";
}

Dog::Dog(const Dog& other) {
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

Dog::~Dog(void) {}

void Dog::makeSound(void) const {
	std::cout << "Auau Auau Auauauauau" << std::endl;
}