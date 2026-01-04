#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>

int main() {
	std::cout << "=== Testando ClapTrap ===" << std::endl;
	ClapTrap ct("Alpha");
	ct.attack("Beta");
	ct.takeDamage(5);
	ct.beRepaired(3);

	std::cout << "\n=== Testando ScavTrap ===" << std::endl;
	ScavTrap st("Guardian");
	st.attack("Intruder");
	st.guardGate();

	std::cout << "\n=== Testando FragTrap ===" << std::endl;
	FragTrap ft("Destroyer");
	ft.attack("Enemy");
	ft.highFivesGuys();

	std::cout << "\n=== Testando encadeamento de destrutores ===" << std::endl;
	{
		FragTrap temp("TempFrag");
		temp.attack("Alpha");
		temp.highFivesGuys();
	}

	std::cout << "\n=== Fim do programa ===" << std::endl;
	return 0;
}
