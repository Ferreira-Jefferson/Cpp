#include "Weapon.hpp"
#include "HumanB.hpp"
#include <iostream>

HumanB::HumanB(std::string name): _weapon(NULL) , _name(name){};

void HumanB::attack(void)
{
	if (_weapon == NULL)
		std::cout << "has no weapon" << std::endl;
	else
		std::cout << _name << " attacks with their" << _weapon->getType() << std::endl;
}
void HumanB::setWeapon(Weapon& weapon){
	 _weapon = &weapon;
}