#include "ClapTrap.hpp"
#include <iostream>

int main() {
	ClapTrap ct1("Alpha");
	ClapTrap ct2("Beta");

	std::cout << std::endl;

	ct1.attack("Beta");   
	ct2.takeDamage(ct1.getAttackDamage()); 
	std::cout << std::endl;

	
	ct2.beRepaired(5);
	std::cout << std::endl;

	for (int i = 0; i < 10; i++) {
		ct1.attack("Beta"); 
	}
	std::cout << std::endl;

	
	ct2.takeDamage(20);   
	ct2.attack("Alpha"); 
	std::cout << std::endl;

	return 0;
}
