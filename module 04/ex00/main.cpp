#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
	const Animal* base = new Animal();
	const Animal* d = new Dog();
	const Animal* c = new Cat();

	std::cout << d->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;

	c->makeSound();
	d->makeSound();
	base->makeSound();

	delete base;
	delete d;
	delete c;

	std::cout << std::endl;

	const WrongAnimal* wrong = new WrongAnimal();
	const WrongAnimal* wrongCat = new WrongCat();

	std::cout << wrongCat->getType() << " " << std::endl;
	wrongCat->makeSound();
	wrong->makeSound();

	delete wrong;
	delete wrongCat;

	return 0;
}
