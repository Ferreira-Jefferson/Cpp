#include "Point.hpp"

static int cross(Point const a, Point const b, Point const p) {
	int x1 = a.getX().getRawBits();
	int y1 = a.getY().getRawBits();
	int x2 = b.getX().getRawBits();
	int y2 = b.getY().getRawBits();
	int xp = p.getX().getRawBits();
	int yp = p.getY().getRawBits();

	return (x2 - x1) * (yp - y1) - (y2 - y1) * (xp - x1);
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {
	int d1 = cross(a, b, point);
	int d2 = cross(b, c, point);
	int d3 = cross(c, a, point);

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;

	bool neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(neg && pos);
}
