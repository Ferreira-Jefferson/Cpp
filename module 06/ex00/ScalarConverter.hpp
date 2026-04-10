#pragma once

#include <string>
#include <iostream>
#include <cctype>
#include <climits>
#include <cstdlib>
#include <sstream>

class ScalarConverter {
    ScalarConverter(void);
    ScalarConverter(const ScalarConverter& copy);
    ScalarConverter& operator=(const ScalarConverter& copy);
    ~ScalarConverter(void);
    
    public:
        static void convert(std::string literal);    
};
