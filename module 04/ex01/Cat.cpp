#include "Cat.hpp"

Cat::Cat(void) {
	std::cout << "Default constructor called Cat" << std::endl;
	type = "Cat";
	_brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat: copy constructor called Cat" << std::endl;
    _brain = new Brain(*other._brain);
    type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat: copy assignment operator called Cat" << std::endl;
    if (this == &other)
        return *this;
    type = other.type;
    if (_brain)
        delete _brain;
    _brain = new Brain(*other._brain);
    return *this;
}

Cat::~Cat(void) {
	std::cout << "Destructor called Cat" << std::endl;
	delete _brain;
}


void Cat::makeSound(void) const {
	std::cout << "Miaaaauuuuuuuuuuu" << std::endl;
}