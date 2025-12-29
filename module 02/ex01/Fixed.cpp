#include "Fixed.hpp"

Fixed::Fixed(void): _valueFixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	_valueFixedPoint = n << _bits;
}

Fixed::Fixed(const float n): _valueFixedPoint(0) {
	std::cout << "Float constructor called" << std::endl;
	_valueFixedPoint = static_cast<int>(roundf(n * (1 << _bits)));
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

float Fixed::toFloat(void) const {
	return static_cast<float>(_valueFixedPoint) / (1 << _bits);
}

int Fixed::toInt(void) const {
	return _valueFixedPoint >> _bits;
}

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) { 
	out << fixed.toFloat();
	return out;
}