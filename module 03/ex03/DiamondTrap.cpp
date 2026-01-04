#include "DiamondTrap.hpp"
#include <iostream>

DiamondTrap::DiamondTrap() : 
	ClapTrap(), FragTrap(), ScavTrap() {
	_name = "Default";
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : 
	ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name) {
	_name = name;
	setHitPoint(100);
	setEnergyPoint(50);
	setAttackDamage(30);
	std::cout << "DiamondTrap constructor called for " << _name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other) : 
	ClapTrap(other), FragTrap(other), ScavTrap(other) {
	*this = other;
	std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other) {
	if (this != &other) {
		ClapTrap::operator=(other);
		_name = other._name;
	}
	std::cout << "DiamondTrap assignment operator called" << std::endl;
	return *this;
}

DiamondTrap::~DiamondTrap() {
	std::cout << "DiamondTrap destructor called for " << _name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout << "DiamondTrap name: " << _name 
			<< " | ClapTrap name: " << ClapTrap::getName() << std::endl;
}
