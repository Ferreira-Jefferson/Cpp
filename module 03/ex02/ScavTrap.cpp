#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>

ScavTrap::ScavTrap() : ClapTrap() {
	std::cout << "ScavTrap default constructor called" << std::endl;
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap constructor called for " << getName() << std::endl;
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(20);
}

ScavTrap::ScavTrap(const ScavTrap& other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructor called" << std::endl;
	*this = other;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other) {
	std::cout << "ScavTrap assignment operator called" << std::endl;
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap destructor called for " << getName() << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (getEnergyPoint() <= 0 || getHitPoint() <= 0) {
		std::cout << "ScavTrap " << getName() << " cannot attack!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << getName() << " fiercely attacks " 
			  << target << ", causing " << getAttackDamage ()
			  << " points of damage!" << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << getName() << " is now in Gate Keeper mode!" << std::endl;
}
