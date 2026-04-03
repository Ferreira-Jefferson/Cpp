#include "parser.hpp"
#include <iostream>

int main(void)
{
    Parser p;
    std::vector<std::string> parts = p.split("hello,world,foo", ',');
    for (size_t i = 0; i < parts.size(); ++i)
        std::cout << parts[i] << std::endl;
    return 0;
}
