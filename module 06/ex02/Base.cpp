#include "Base.hpp"
#include <cstdlib>
#include <iostream>

// Base
Base::Base() {}
Base::Base(const Base& other) { (void)other; }
Base& Base::operator=(const Base& other) { (void)other; return *this; }
Base::~Base() {}

// A
A::A() {}
A::A(const A& other) : Base(other) {}
A& A::operator=(const A& other) { Base::operator=(other); return *this; }
A::~A() {}

// B
B::B() {}
B::B(const B& other) : Base(other) {}
B& B::operator=(const B& other) { Base::operator=(other); return *this; }
B::~B() {}

// C
C::C() {}
C::C(const C& other) : Base(other) {}
C& C::operator=(const C& other) { Base::operator=(other); return *this; }
C::~C() {}

Base* generate(void)
{
	switch (std::rand() % 3)
	{
		case 0: return new A();
		case 1: return new B();
		default: return new C();
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (...) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
	} catch (...) {}
}
