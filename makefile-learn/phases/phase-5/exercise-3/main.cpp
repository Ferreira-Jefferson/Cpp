#include "utils.hpp"
#include "parser.hpp"
#include <iostream>

int main(void)
{
    std::string line = "  hello , world , foo  ";
    std::vector<std::string> parts = split(line, ',');
    for (size_t i = 0; i < parts.size(); ++i)
        std::cout << trim(parts[i]) << std::endl;
    return 0;
}
