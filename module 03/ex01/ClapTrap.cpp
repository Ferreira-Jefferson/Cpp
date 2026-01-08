#include "ClapTrap.hpp"
#include <iostream>

ClapTrap::ClapTrap(void) : _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hitPoint(10), _energyPoint(10), _attackDamage(0) {
	std::cout << "Constructor with name called for " << _name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other) {
	*this = other;
	std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap(void) {
	std::cout << "Destructor called for " << _name << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (&other == this)
		return (*this);
	this->_name = other.getName();
	this->_hitPoint = other.getHitPoint();
	this->_energyPoint = other.getEnergyPoint();
	this->_attackDamage = other.getAttackDamage();
	return (*this);
}

std::string ClapTrap::getName(void) const {
	return (_name);
}

int ClapTrap::getHitPoint(void) const {
	return (_hitPoint);
}

int ClapTrap::getEnergyPoint(void) const {
	return (_energyPoint);
}

int ClapTrap::getAttackDamage(void) const {
	return (_attackDamage);
}

void ClapTrap::setName(std::string name) {
	_name = name;
}

void ClapTrap::setHitPoint(int v) {
	_hitPoint = v;
}

void ClapTrap::setEnergyPoint(int v) {
	_energyPoint = v;
}

void ClapTrap::setAttackDamage(int v) {
	_attackDamage = v;
}

void ClapTrap::attack(const std::string& target) {
	if (_energyPoint <= 0 || _hitPoint <= 0) {
		std::cout << "ClapTrap " << _name 
		<< " cannot attack, no energy or hit points left!" << std::endl;
		return;
	}
	std::cout << "ClapTrap " << _name << " attacks " 
			  << target << ", causing " << _attackDamage
			  << " points of damage!" << std::endl;
	_energyPoint--;
}

void ClapTrap::takeDamage(unsigned int amount) {
	if (_hitPoint <= 0) {
		std::cout << "ClapTrap " << _name 
		<< " cannot take more damage, already destroyed!" << std::endl;
		return;
	}
	_hitPoint -= amount;
	std::cout << "ClapTrap " << _name << " takes " 
			  << amount << " points of damage! Remaining HP: " << _hitPoint << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energyPoint <= 0 || _hitPoint <= 0) {
		std::cout << "ClapTrap " << _name 
		<< " cannot repair, no energy or already destroyed!" << std::endl;
		return;
	}
	_hitPoint += amount;
	_energyPoint--;
	std::cout << "ClapTrap " << _name << " is repaired, recovering " 
			  << amount << " hit points! Current HP: " << _hitPoint 
			  << ", Energy: " << _energyPoint << std::endl;
}
