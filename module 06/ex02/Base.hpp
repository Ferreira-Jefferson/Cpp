#ifndef BASE_HPP
#define BASE_HPP

class Base
{
	public:
		Base();
		Base(const Base& other);
		Base& operator=(const Base& other);
		virtual ~Base();
};

class A : public Base
{
	public:
		A();
		A(const A& other);
		A& operator=(const A& other);
		~A();
};

class B : public Base
{
	public:
		B();
		B(const B& other);
		B& operator=(const B& other);
		~B();
};

class C : public Base
{
	public:
		C();
		C(const C& other);
		C& operator=(const C& other);
		~C();
};

Base*	generate(void);
void	identify(Base* p);
void	identify(Base& p);

#endif
