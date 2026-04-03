#ifndef STACK_HPP
# define STACK_HPP

# include <deque>

class Stack
{
public:
    void    push(int value);
    int     pop(void);
    bool    empty(void) const;
private:
    std::deque<int> _data;
};

#endif
