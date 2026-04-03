#ifndef LOGGER_HPP
# define LOGGER_HPP

# include <string>

class Logger
{
public:
    Logger(const std::string& prefix);
    void log(const std::string& msg) const;
private:
    std::string _prefix;
};

#endif
