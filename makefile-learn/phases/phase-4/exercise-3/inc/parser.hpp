#ifndef PARSER_HPP
# define PARSER_HPP

# include <string>
# include <vector>

class Parser
{
public:
    std::vector<std::string> split(const std::string& str, char delim) const;
};

#endif
