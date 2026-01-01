#include "Fixed.hpp"

const int Fixed::_bits = 8;

std::ostream& operator<<(std::ostream& out, const Fixed& f) {
	out << f.toFloat();
	return (out);
}

Fixed::Fixed(void): _valueFixedPoint(0) {}

Fixed::Fixed(const Fixed& other) {
	*this = other;
}

Fixed::~Fixed(void) {
	_valueFixedPoint = 0;
}

Fixed& Fixed::operator=(const Fixed& other) {
	if (&other == this)
		return (*this);
	this->_valueFixedPoint = other.getRawBits();
	return (*this);	
}

Fixed::Fixed(const int n) {
	_valueFixedPoint = n << _bits;
}

Fixed::Fixed(const float n) {
	_valueFixedPoint = static_cast<int>(roundf(n * (1 << _bits)));
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
	return (_valueFixedPoint >> 8);
}

bool Fixed::operator>(const Fixed& other) const {
	return (_valueFixedPoint > other.getRawBits());	
}

bool Fixed::operator<(const Fixed& other) const {
	return (_valueFixedPoint < other.getRawBits());	
}

bool Fixed::operator>=(const Fixed& other) const {
	return (_valueFixedPoint >= other.getRawBits());	
}

bool Fixed::operator<=(const Fixed& other) const {
	return (_valueFixedPoint <= other.getRawBits());	
}

bool Fixed::operator==(const Fixed& other) const {
	return (_valueFixedPoint == other.getRawBits());	
}

bool Fixed::operator!=(const Fixed& other) const {
	return (_valueFixedPoint != other.getRawBits());	
}

Fixed Fixed::operator+(const Fixed& other) const {
	Fixed result;
	result.setRawBits(_valueFixedPoint + other.getRawBits());
	return (result);
}

Fixed Fixed::operator-(const Fixed& other) const {
	Fixed result;
	result.setRawBits(_valueFixedPoint - other.getRawBits());
	return (result);
}

Fixed Fixed::operator*(const Fixed& other) const {
	Fixed result;
	long tmp = static_cast<long>(_valueFixedPoint) * static_cast<long>(other.getRawBits());
	result.setRawBits(static_cast<int>(tmp >> _bits));
	return (result);
}

Fixed Fixed::operator/(const Fixed& other) const {
	Fixed result;
	long tmp = static_cast<long>(_valueFixedPoint << _bits) / static_cast<long>(other.getRawBits());
	result.setRawBits(static_cast<int>(tmp));
	return (result);
}

Fixed& Fixed::operator++() {
	_valueFixedPoint++;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed temp(*this);
	_valueFixedPoint++;
	return (temp);
}

Fixed& Fixed::operator--() {
	_valueFixedPoint--;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed temp(*this);
	_valueFixedPoint--;
	return (temp);
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