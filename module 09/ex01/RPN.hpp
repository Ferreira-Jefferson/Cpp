#pragma once

#include <string>
#include <stack>

class RPN
{
	public:
		RPN();
		RPN(RPN const &other);
		RPN &operator=(RPN const &other);
		~RPN();

		int evaluate(std::string const &expression);

	private:
		std::stack<int> _stack;
};
