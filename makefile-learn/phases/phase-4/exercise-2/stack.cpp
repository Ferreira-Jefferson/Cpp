#include "stack.hpp"
#include <stdexcept>

void Stack::push(int value) { _data.push_back(value); }

int Stack::pop(void)
{
    if (_data.empty())
        throw std::underflow_error("Stack is empty");
    int val = _data.back();
    _data.pop_back();
    return val;
}

bool Stack::empty(void) const { return _data.empty(); }
