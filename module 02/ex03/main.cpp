#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

int main() {
	Point a(0, 0);
	Point b(10, 0);
	Point c(0, 10);

	Point inside(3, 3);
	Point outside(10, 10);
	Point onEdge(5, 0);
	Point vertex(0, 0);

	std::cout << std::endl;
	std::cout << "Inside (3,3): " << bsp(a, b, c, inside) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Outside (10,10): " << bsp(a, b, c, outside) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "On edge (5,0): " << bsp(a, b, c, onEdge) << std::endl;
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "Vertex (0,0): " << bsp(a, b, c, vertex) << std::endl;
	std::cout << std::endl;

	return 0;
}
