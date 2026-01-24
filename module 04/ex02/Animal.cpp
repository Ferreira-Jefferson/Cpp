#include "Animal.hpp"
#include <iostream>

Animal::Animal() {
    std::cout << "Animal: default constructor called" << std::endl;
}

Animal::Animal(const Animal& other) {
    std::cout << "Animal: copy constructor called" << std::endl;
    *this = other;
}

Animal& Animal::operator=(const Animal& other) {
    std::cout << "Animal: copy assignment operator called" << std::endl;
    if (this == &other)
        return *this;
    type = other.type;
    return *this;
}

Animal::~Animal() {
    std::cout << "Animal: destructor called" << std::endl;
}

std::string Animal::getType() const {
    return type;
}

void Animal::makeSound() const {
    std::cout << "Animal: default sound" << std::endl;
}
