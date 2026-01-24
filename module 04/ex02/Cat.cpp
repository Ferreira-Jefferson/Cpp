#include "Cat.hpp"
#include <iostream>

Cat::Cat() {
    std::cout << "Cat: default constructor called" << std::endl;
    type = "Cat";
    _brain = new Brain();
}

Cat::Cat(const Cat& other) : Animal(other) {
    std::cout << "Cat: copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
    type = other.type;
}

Cat& Cat::operator=(const Cat& other) {
    std::cout << "Cat: copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    type = other.type;
    if (_brain)
        delete _brain;
    _brain = new Brain(*other._brain);
    return *this;
}

Cat::~Cat() {
    std::cout << "Cat: destructor called" << std::endl;
    delete _brain;
}

void Cat::makeSound() const {
    std::cout << "Cat: meow" << std::endl;
}
