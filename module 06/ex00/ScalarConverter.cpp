#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter(void) {}

ScalarConverter::ScalarConverter(const ScalarConverter&) {}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter&) {
    return *this;
}

ScalarConverter::~ScalarConverter(void) {}

static bool isSpecial(const std::string& literal) {
    std::string special[] = {"nan", "nanf", "+inf", "-inf", "+inff", "-inff"};
    for (int i = 0; i < 6; i++)
        if (literal == special[i])
            return true;
    return false;
}

static int getPrecision(const std::string& literal) {
    std::size_t dot = literal.find('.');

    if (dot == std::string::npos)
        return 1;
    std::size_t end = literal.length();
    if (literal[end - 1] == 'f')
        end--;
    int prec = static_cast<int>(end - dot - 1);
    return prec < 1 ? 1 : prec;
}

static void printSpecial(const std::string& literal) {
    std::string base;
    
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        base = literal.substr(0, literal.length() - 1);
    else
        base = literal;

    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << base << "f" << std::endl;
    std::cout << "double: " << base << std::endl;
}

void ScalarConverter::convert(std::string literal) {
    if (isSpecial(literal)) {
        printSpecial(literal);
        return;
    }

    char   c;
    int    i;
    float  f;
    double d;

    if (literal.length() == 3 && literal[0] == '\''
        && literal[2] == '\'' && std::isprint(literal[1])) {
        std::ostringstream oss;
        oss << static_cast<int>(literal[1]);
        literal = oss.str();
    } else if (literal.length() == 1 && !std::isdigit(literal[0]) && std::isprint(literal[0])) {
        std::ostringstream oss;
        oss << static_cast<int>(literal[0]);
        literal = oss.str();
    }
    char *end;
    if (literal.find('.') != std::string::npos) {
        d = std::strtod(literal.c_str(), &end);
        if (*end != '\0' && !(*end == 'f' && *(end + 1) == '\0')) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        c = static_cast<char>(d);
        f = static_cast<float>(d);
        i = static_cast<int>(d);
        c = static_cast<char>(d);
    } else {
        long l = std::strtol(literal.c_str(), &end, 10);
        if (*end != '\0' || literal.empty()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        i = static_cast<int>(l);
        c = static_cast<char>(l);
        f = static_cast<float>(l);
        d = static_cast<double>(l);
    }

    // print char
    if (d < 0 || d > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<int>(c)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << c << "'" << std::endl;

    // print int
    if (d < INT_MIN || d > INT_MAX)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    // print float and double
    int prec = getPrecision(literal);
    std::cout << std::fixed;
    std::cout.precision(prec);
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}
