#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main()
{
	std::cout << "=== MutantStack ===" << std::endl;
	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;

		mstack.pop();

		std::cout << mstack.size() << std::endl;

		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);

		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}

	std::cout << "=== std::list (same output expected) ===" << std::endl;
	{
		std::list<int> mstack;

		mstack.push_back(5);
		mstack.push_back(17);

		std::cout << mstack.back() << std::endl;

		mstack.pop_back();

		std::cout << mstack.size() << std::endl;

		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);

		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();

		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "=== copy & const iteration ===" << std::endl;
	{
		MutantStack<int> a;
		a.push(1);
		a.push(2);
		a.push(3);

		MutantStack<int> b(a);
		MutantStack<int> c;
		c = a;

		std::cout << "reverse b: ";
		for (MutantStack<int>::reverse_iterator it = b.rbegin(); it != b.rend(); ++it)
			std::cout << *it << " ";
		std::cout << std::endl;

		std::cout << "copy c size: " << c.size() << std::endl;
	}

	return 0;
}
