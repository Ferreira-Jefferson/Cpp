#include "calc.hpp"
#include <iostream>

int main(void)
{
    Calc c;
    std::cout << "2 + 3 = " << c.add(2, 3) << std::endl;
    std::cout << "4 * 5 = " << c.mul(4, 5) << std::endl;
    return 0;
}
