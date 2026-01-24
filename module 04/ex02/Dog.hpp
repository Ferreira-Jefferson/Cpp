#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog: public Animal {
public:
    Dog();
    Dog(const Dog& other);
    Dog& operator=(const Dog& other);
    ~Dog();

    void makeSound() const;

    void setIdea(int idx, const std::string& idea);
    std::string getIdea(int idx) const;

private:
    Brain* _brain;
};
