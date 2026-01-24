#include "Dog.hpp"
#include <iostream>

Dog::Dog() {
    std::cout << "Dog: default constructor called" << std::endl;
    type = "Dog";
    _brain = new Brain();
}

Dog::Dog(const Dog& other) : Animal(other) {
    std::cout << "Dog: copy constructor called" << std::endl;
    _brain = new Brain(*other._brain);
    type = other.type;
}

Dog& Dog::operator=(const Dog& other) {
    std::cout << "Dog: copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    type = other.type;
    if (_brain)
        delete _brain;
    _brain = new Brain(*other._brain);
    return *this;
}

Dog::~Dog() {
    std::cout << "Dog: destructor called" << std::endl;
    delete _brain;
}

void Dog::makeSound() const {
    std::cout << "Dog: woof woof" << std::endl;
}

void Dog::setIdea(int idx, const std::string& idea) {
    if (idx >= 0 && idx < 100)
        _brain->ideas[idx] = idea;
}

std::string Dog::getIdea(int idx) const {
    if (idx >= 0 && idx < 100)
        return _brain->ideas[idx];
    return std::string();
}
