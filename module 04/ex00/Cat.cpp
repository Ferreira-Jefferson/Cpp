#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Default constructor called Cat" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat& other) {
	std::cout << "Copy constructor called Cat" << std::endl;
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	std::cout << "Copy assignment operator called Cat" << std::endl;
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

Cat::~Cat(void) {
	std::cout << "Destructor called Cat" << std::endl;
}


void Cat::makeSound(void) const {
	std::cout << "Miaaaauuuuuuuuuuu" << std::endl;
}