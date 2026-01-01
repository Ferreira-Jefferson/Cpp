#include "Fixed.hpp"

class Point {
	private:
		const Fixed _x;
		const Fixed _y;
	
	public:
		Point(void);
		Point(const Point& other);
		Point& operator=(const Point& other);
		~Point();

		Point(const float x, const float y);

		Fixed getX() const;
		Fixed getY() const;
};