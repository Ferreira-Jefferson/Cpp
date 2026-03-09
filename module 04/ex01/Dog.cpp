#include "Dog.hpp"

Dog::Dog(void) {
	std::cout << "Default constructor called Dog" << std::endl;
	type = "Dog";
	_brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog: copy constructor called Dog" << std::endl;
    _brain = new Brain(*other._brain);
    type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog: copy assignment operator called Dog" << std::endl;
    if (this == &other)
        return *this;
    type = other.type;
    if (_brain)
        delete _brain;
    _brain = new Brain(*other._brain);
    return *this;
}

Dog::~Dog(void) {
	std::cout << "Destructor called Dog" << std::endl;
	delete _brain;
}

void Dog::makeSound(void) const {
	std::cout << "Auau Auau Auauauauau" << std::endl;
}