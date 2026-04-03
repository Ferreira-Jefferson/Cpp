#include "utils.hpp"
#include <algorithm>
#include <cctype>

std::string trim(const std::string& s)
{
    size_t start = s.find_first_not_of(" \t");
    size_t end = s.find_last_not_of(" \t");
    if (start == std::string::npos)
        return "";
    return s.substr(start, end - start + 1);
}
