#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main()
{
	const Animal* ad = new Dog();
	const Animal* ac = new Cat();
	delete ad;
	delete ac;

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

	Cat* c1 = new Cat();
	Cat* c2 = new Cat(*c1);

	std::cout << c1->getType() << std::endl;
	std::cout << c2->getType() << std::endl;

	c2->setType("Cat copy");
	std::cout << "Deep copy c1: " << c1->getType() << std::endl;
	std::cout << "Deep copy c2: " << c2->getType() << std::endl;
	
	std::cout << std::endl;

	delete c1;
	delete c2;

	return 0;
}
