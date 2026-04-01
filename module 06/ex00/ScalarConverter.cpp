#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

ScalarConverter::~ScalarConverter(void) {}

void ScalarConverter::convert(std::string literal) {
    std::string special[] = {"nan", "nanf", "+inf", "-inf", "+inff", "-inff"};

    for (int i=0; i < (int)(sizeof(special) / sizeof(special[0])); i++)
    {
        if (literal.compare(special[i]))
        {
            std::cout << "char: " << special[i] << std::endl;
            std::cout << "int: " << special[i] << std::endl;
            std::cout << "float: " << special[i] + "f" << std::endl;
            std::cout << "double: " << special[i] << std::endl;
            return ;
        }
    }
    // char 
    if (literal[0] == '\'')
    {
        if (literal.length() != 3)
            std::cout << "char: " << "impossible" << std::endl;
        else if (!isprint(literal[1]))
            std::cout << "char: " << "not displayable" << std::endl;
        else
        {
            std::cout << "char: " << literal[1] << std::endl;
            std::cout << "int: " << static_cast<int>(literal[1]) << std::endl;
            std::cout << "float: " << static_cast<float>(literal[1]) << std::endl;
            std::cout << "double: " << static_cast<double>(literal[1]) << std::endl;
        }
        return ;
    }
    // float

    // double 
    // int

}