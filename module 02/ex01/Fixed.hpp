#pragma once

#include <iostream>
#include <cmath>

class Fixed {
	private:
		int _valueFixedPoint;
		static const int _bits = 8;

	public:
		Fixed(void);
		Fixed(const int n);
		Fixed(const float n);

		Fixed(const Fixed& copy);
		Fixed& operator=(const Fixed& copy);
		~Fixed(void);

		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);