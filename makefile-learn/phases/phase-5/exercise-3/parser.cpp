#include "parser.hpp"
#include <sstream>

std::vector<std::string> split(const std::string& str, char delim)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream ss(str);
    while (std::getline(ss, token, delim))
        tokens.push_back(token);
    return tokens;
}
