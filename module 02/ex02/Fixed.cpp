#include "Fixed.hpp"

const int Fixed::_bits = 8;

std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
	out << fixed.toFloat();
	return (out);
}

Fixed::Fixed(void): _valueFixedPoint(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed(void){
	std::cout << "Destructor called" << std::endl;
	_valueFixedPoint = 0;
}

Fixed::Fixed(const Fixed& copy) {
	std::cout << "Copy constructor called" << std::endl;
	*this = copy;
}

Fixed::Fixed(const int n) {
	std::cout << "Int constructor called" << std::endl;
	_valueFixedPoint = n << _bits;
}

Fixed::Fixed(const float n) {
	std::cout << "Float constructor called" << std::endl;
	_valueFixedPoint = static_cast<int>(roundf(n * (1 << _bits)));
}

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (&other == this)
		return (*this);
	_valueFixedPoint = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits(void) const {
	return (_valueFixedPoint);
}

void Fixed::setRawBits(const int raw) {
	_valueFixedPoint = raw;
}

float Fixed::toFloat(void) const {
	return (static_cast<float>(_valueFixedPoint) / (1 << _bits));
}

int Fixed::toInt(void) const {
	return (_valueFixedPoint >> _bits);
}

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return (a < b ? a : b);
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return (a < b ? a : b);
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return (a > b ? a : b);
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return (a > b ? a : b);
}

bool Fixed::operator>(const Fixed& other) const {
	return (_valueFixedPoint > other._valueFixedPoint);
}

bool Fixed::operator<(const Fixed& other) const {
	return (_valueFixedPoint < other._valueFixedPoint);
}

bool Fixed::operator>=(const Fixed& other) const {
	return (_valueFixedPoint >= other._valueFixedPoint);
}

bool Fixed::operator<=(const Fixed& other) const {
	return (_valueFixedPoint <= other._valueFixedPoint);
}

bool Fixed::operator==(const Fixed& other) const {
	return (_valueFixedPoint == other._valueFixedPoint);
}

bool Fixed::operator!=(const Fixed& other) const {
	return (_valueFixedPoint != other._valueFixedPoint);
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(_valueFixedPoint + other._valueFixedPoint);
	return result;
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(_valueFixedPoint - other._valueFixedPoint);
	return result;
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
		
	long tmp = (long)_valueFixedPoint * (long)other._valueFixedPoint;
	result.setRawBits((int)(tmp >> _bits));
	return result;
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
		
	long tmp = ((long)_valueFixedPoint << _bits) / (long)other._valueFixedPoint;
	result.setRawBits((int)tmp);
	return result;
}

Fixed& Fixed::operator++(void) { 
	_valueFixedPoint++;
	return *this;
}

Fixed Fixed::operator++(int) { 
	Fixed temp(*this);
	_valueFixedPoint++;
	return temp;
}

Fixed& Fixed::operator--() { 
	_valueFixedPoint--;
	return *this;
}

Fixed Fixed::operator--(int) { 
	Fixed temp(*this);
	_valueFixedPoint--;
	return temp;
}
