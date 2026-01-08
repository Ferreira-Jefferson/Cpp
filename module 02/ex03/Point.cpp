#include "Point.hpp"

Point::Point(void): _x(0), _y(0) {
	std::cout << "Default constructor called" << std::endl;
}

Point::Point(const Point& other) : _x(other._x), _y(other._y) {
	std::cout << "Copy constructor called" << std::endl;
}

Point& Point::operator=(const Point& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	(void)other;
	return *this;
}

Point::~Point() {
	std::cout << "Destructor called" << std::endl;
}

Point::Point(const float x, const float y): _x(x), _y(y) {}

Fixed Point::getX() const { 
	return _x;
}

Fixed Point::getY() const {
	return _y;
}