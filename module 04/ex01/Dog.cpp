#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Default constructor called Dog" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog& other) {
	std::cout << "Copy constructor called Dog" << std::endl;
	*this = other;
}

Dog& Dog::operator=(const Dog& other) {
	std::cout << "Copy assignment operator called Dog" << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

Dog::~Dog(void) {
	std::cout << "Destructor called Dog" << std::endl;
}

void Dog::makeSound(void) const {
	std::cout << "Auau Auau Auauauauau" << std::endl;
}