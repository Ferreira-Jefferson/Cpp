#include "counter.hpp"
#include <iostream>

Counter::Counter(void) : _count(0) {}
void Counter::increment(void) { _count++; }
void Counter::decrement(void) { _count--; }
int  Counter::value(void) const { return _count; }
