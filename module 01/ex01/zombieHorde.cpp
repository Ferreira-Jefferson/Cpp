#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name) {
	if (N <= 0)
		return (NULL);

	Zombie *zombies = new Zombie[N];
	std::string name_tmp;

	for (int i=0; i < N; i++)
	{
		name_tmp = name + "-" + std::string(1, i + '0');
		zombies[i].setName(name_tmp);
	}
	return (zombies);
}