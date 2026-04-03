#include "greeter.hpp"
#include <iostream>

Greeter::Greeter(const std::string& name) : _name(name) {}

void Greeter::greet(void) const
{
    std::cout << "Hello, " << _name << "!" << std::endl;
}
