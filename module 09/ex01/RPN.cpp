#include "RPN.hpp"
#include <sstream>
#include <stdexcept>

RPN::RPN()
{
}

RPN::RPN(RPN const &other)
{
	*this = other;
}

RPN &RPN::operator=(RPN const &other)
{
	if (this != &other)
		_stack = other._stack;
	return *this;
}

RPN::~RPN()
{
}

int RPN::evaluate(std::string const &expression)
{
	std::istringstream iss(expression);
	std::string token;

	while (iss >> token)
	{
		if (token.size() != 1)
			throw std::runtime_error("Error");

		char c = token[0];
		if (c >= '0' && c <= '9')
			_stack.push(c - '0');
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			if (_stack.size() < 2)
				throw std::runtime_error("Error");
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			if (c == '+')
				_stack.push(a + b);
			else if (c == '-')
				_stack.push(a - b);
			else if (c == '*')
				_stack.push(a * b);
			else
			{
				if (b == 0)
					throw std::runtime_error("Error");
				_stack.push(a / b);
			}
		}
		else
			throw std::runtime_error("Error");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("Error");
	return _stack.top();
}
