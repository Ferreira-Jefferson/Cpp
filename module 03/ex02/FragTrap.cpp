#include "FragTrap.hpp"
#include <iostream>

FragTrap::FragTrap() : ClapTrap() {
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << "FragTrap default constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	setHitPoint(100);
	setEnergyPoint(100);
	setAttackDamage(30);
	std::cout << "FragTrap constructor called for " << getName() << std::endl;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	*this = other;
	std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	std::cout << "FragTrap assignment operator called" << std::endl; 
	if (this != &other) {
		ClapTrap::operator=(other);
	}
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap destructor called for " << getName() << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (getEnergyPoint() <= 0 || getHitPoint() <= 0) {
		std::cout << "FragTrap " << getName() << " cannot attack!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << getName() << " launches a powerful attack on " 
			<< target << ", causing " << getAttackDamage() 
			<< " points of damage!" << std::endl;
	setEnergyPoint(getEnergyPoint() - 1);
}

void FragTrap::highFivesGuys(void) {
	std::cout << "FragTrap " << getName() << " requests a positive high five! ✋" << std::endl;
}
