#include "ScalarConverter.hpp"
#include <iostream>

ScalarConverter::ScalarConverter(void) {}

void ScalarConverter::convert(const std::string& literal)
{
    std::cout << "Converting: " << literal << std::endl;
}
