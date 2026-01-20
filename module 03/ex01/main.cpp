#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>

int main() {
	std::cout << "=== Create ClapTrap ===" << std::endl;
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

	std::cout << "=== Create ScavTrap ===" << std::endl;
	ScavTrap st1("Guardian");
	ScavTrap st2("Sentinel");

	std::cout << std::endl;

	st1.attack("Intruder");  
	st2.takeDamage(st1.getAttackDamage()); 
	std::cout << std::endl;

	st2.beRepaired(15);
	std::cout << std::endl;

	st1.guardGate();		 
	std::cout << std::endl;

	std::cout << "=== Testing destructor chaining ===" << std::endl;
	{
		ScavTrap temp("Temporary");
		temp.attack("Alpha");
		temp.guardGate();
	}

	std::cout << "\n=== End Program ===" << std::endl;
	return 0;
}
