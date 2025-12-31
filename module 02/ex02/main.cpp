#include "Fixed.hpp"

int main(void) {
	std::cout << "=== Teste de construtores ===" << std::endl;
	Fixed a;
	Fixed b(10);
	Fixed c(42.42f);
	Fixed d(b);

	std::cout << "a = " << a << std::endl;
	std::cout << "b = " << b << std::endl;
	std::cout << "c = " << c << std::endl;
	std::cout << "d = " << d << std::endl;

	std::cout << "\n=== Teste de atribuição ===" << std::endl;
	a = c;
	std::cout << "a (após atribuição de c) = " << a << std::endl;

	std::cout << "\n=== Teste de comparação ===" << std::endl;
	std::cout << "b: " << b << "  c: " << c << "  d: " << d << std::endl;
	std::cout << "b > c ? " << (b > c) << std::endl;
	std::cout << "b < c ? " << (b < c) << std::endl;
	std::cout << "b >= d ? " << (b >= d) << std::endl;
	std::cout << "b <= d ? " << (b <= d) << std::endl;
	std::cout << "b == d ? " << (b == d) << std::endl;
	std::cout << "b != c ? " << (b != c) << std::endl;

	std::cout << "\n=== Teste de aritméticos ===" << std::endl;
	std::cout << "b: " << b << "  c: " << c << std::endl;
	Fixed e = b + c;
	Fixed f = c - b;
	Fixed g = b * Fixed(2);
	Fixed h = c / Fixed(2);

	std::cout << "b + c = " << e << std::endl;
	std::cout << "c - b = " << f << std::endl;
	std::cout << "b * 2 = " << g << std::endl;
	std::cout << "c / 2 = " << h << std::endl;

	std::cout << "\n=== Teste de incremento/decremento ===" << std::endl;
	Fixed i = Fixed(1);
	std::cout << "i = " << i << std::endl;
	std::cout << "++i = " << ++i << std::endl;
	std::cout << "i = " << i << std::endl;
	std::cout << "i++ = " << i++ << std::endl;
	std::cout << "i = " << i << std::endl;
	std::cout << "--i = " << --i << std::endl;
	std::cout << "i = " << i << std::endl;
	std::cout << "i-- = " << i-- << std::endl;
	std::cout << "i = " << i << std::endl;

	std::cout << "\n=== Teste de min/max ===" << std::endl;
	Fixed j(3.14f);
	Fixed k(2.71f);
	std::cout << "j: " << j << "  k: " << k << std::endl; 
	
	std::cout << "min(j, k) = " << Fixed::min(j, k) << std::endl;
	std::cout << "max(j, k) = " << Fixed::max(j, k) << std::endl;
	std::cout << std::endl;
	
	const Fixed l(100);
	const Fixed m(200);
	std::cout << "l: " << l << "  m: " << m << std::endl; 

	std::cout << "min(l, m) = " << Fixed::min(l, m) << std::endl;
	std::cout << "max(l, m) = " << Fixed::max(l, m) << std::endl;

	return 0;
}
