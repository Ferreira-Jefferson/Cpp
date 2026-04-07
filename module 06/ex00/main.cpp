#include "ScalarConverter.hpp"

/*
void test(const std::string& literal) {
    std::cout << "--- Input: " << literal << " ---" << std::endl;
    ScalarConverter::convert(literal);
    std::cout << std::endl;
}

int main(void) {
    test("'a'");
    test("'Z'");
    test("0");
    test("42");
    test("-42");
    test("2147483647");
    test("2147483648");
    test("3.14f");
    test("-3.14f");
    test("0.0f");
    test("3.14");
    test("-3.14");
    test("0.0");
    test("nan");
    test("nanf");
    test("+inf");
    test("-inf");
    test("+inff");
    test("-inff");
    test("abc");
    test("");
    return 0;
}
*/

int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }
    ScalarConverter::convert(argv[1]);
    return 0;
}
