#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    const int N = 10;
    Animal* animals[N];

    for (int i = 0; i < N; ++i) {
        if (i < N/2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << std::endl;

    for (int i = 0; i < N; ++i) {
        animals[i]->makeSound();
    }

    std::cout << std::endl;

    Dog* d1 = new Dog();
    d1->setIdea(0, "chase the ball");
    Dog d2 = *d1;
    d1->setIdea(0, "sleep");
    std::cout << "d1 brain idea[0]: " << d1->getIdea(0) << std::endl;
    std::cout << "d2 brain idea[0]: " << d2.getIdea(0) << std::endl;

    delete d1;

    for (int i = 0; i < N; ++i)
        delete animals[i];

    return 0;
}
