#include "Cat.hpp"

Cat::Cat(void) {
	type = "Cat";
}

Cat::Cat(const Cat& other) {
	*this = other;
}

Cat& Cat::operator=(const Cat& other) {
	if (this == &other)
		return (*this);
	type = other.type;
	return (*this);
}

Cat::~Cat(void) {}


void Cat::makeSound(void) const {
	std::cout << "Miaaaauuuuuuuuuuu" << std::endl;
}