#include "stack.hpp"
#include <iostream>

int main(void)
{
    Stack s;
    s.push(10);
    s.push(20);
    std::cout << s.pop() << std::endl;
    std::cout << s.pop() << std::endl;
    return 0;
}
