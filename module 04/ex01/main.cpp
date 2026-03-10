#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << std::endl;

	const int N = 10;
	Animal* animals[N];

	for (int i = 0; i < N / 2; i++)
		animals[i] = new Dog();
	for (int i = N / 2; i < N; i++)
		animals[i] = new Cat();

	for (int i = 0; i < N; i++)
		delete animals[i];

	std::cout << std::endl;

	Dog basic;
	{
		Dog tmp = basic;
	}

	return 0;
}
