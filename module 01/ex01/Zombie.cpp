#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void) {}

void Zombie::setName(std::string name)
{
	_name = name;
}
void Zombie::announce(void) {
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie(void){
	std::cout << "Destroyer: " << _name << std::endl;
}



