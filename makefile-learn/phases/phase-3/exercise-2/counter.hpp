#ifndef COUNTER_HPP
# define COUNTER_HPP

class Counter
{
public:
    Counter(void);
    void increment(void);
    void decrement(void);
    int  value(void) const;
private:
    int _count;
};

#endif
