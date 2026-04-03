#include "parser.hpp"
#include <sstream>

std::vector<std::string> Parser::split(const std::string& str, char delim) const
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream ss(str);
    while (std::getline(ss, token, delim))
        tokens.push_back(token);
    return tokens;
}
