#ifndef GREETER_HPP
# define GREETER_HPP

# include <string>

class Greeter
{
public:
    Greeter(const std::string& name);
    void greet(void) const;
private:
    std::string _name;
};

#endif
