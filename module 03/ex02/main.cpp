#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
	std::cout << "=== Testing ClapTrap ===" << std::endl;
	ClapTrap ct("Alpha");
	ct.attack("Beta");
	ct.takeDamage(5);
	ct.beRepaired(3);

	std::cout << "\n=== Testing ScavTrap ===" << std::endl;
	ScavTrap st("Guardian");
	st.attack("Intruder");
	st.guardGate();

	std::cout << "\n=== Testing FragTrap ===" << std::endl;
	FragTrap ft("Destroyer");
	ft.attack("Enemy");
	ft.highFivesGuys();

	std::cout << "\n=== Testing destructor chaining ===" << std::endl;
	{
		FragTrap temp("TempFrag");
		temp.attack("Alpha");
		temp.highFivesGuys();
	}

	std::cout << "\n=== End Program ===" << std::endl;
	return 0;
}
