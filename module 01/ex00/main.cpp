#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main(void)
{
	Zombie *zombie = newZombie("heapZombie");
	zombie->announce();

	randomChump("Stack Zombie");

	delete zombie;
	return (0);
}