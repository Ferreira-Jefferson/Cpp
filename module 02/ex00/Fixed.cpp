#include <iostream>
#include "Fixed.hpp"

const int Fixed::_bits = 8;

Fixed::Fixed(void): _valueFixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	_valueFixedPoint = copy.getRawBits();
}

Fixed& Fixed::operator=(const Fixed& copy) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &copy)
		_valueFixedPoint = copy.getRawBits();
	return (*this);
}

Fixed::~Fixed(void) {
	std::cout << "Destructor called" << std::endl;
}


int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called"  << std::endl;
	return (_valueFixedPoint);
}

void Fixed::setRawBits(int const raw) {
	std::cout << "setRawBits member function called" << std::endl;
	_valueFixedPoint = raw;

}
