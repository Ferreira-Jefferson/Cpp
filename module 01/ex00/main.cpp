#include "Zombie.hpp"
#include "newZombie.cpp"
#include "randomChump.cpp"

int main(void)
{
	Zombie *zombie = newZombie("heapZombie");
	zombie->announce();

	randomChump("Stack Zombie");

	delete zombie;
	return (0);
}