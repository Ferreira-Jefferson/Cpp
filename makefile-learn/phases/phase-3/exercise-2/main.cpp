#include "counter.hpp"
#include <iostream>

int main(void)
{
    Counter c;
    c.increment();
    c.increment();
    c.decrement();
    std::cout << "Counter: " << c.value() << std::endl;
    return 0;
}
