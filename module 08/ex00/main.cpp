#include "easyfind.hpp"
#include <iostream>
#include <vector>
#include <list>

int main()
{
	std::vector<int> v;
	for (int i = 0; i < 10; ++i)
		v.push_back(i * 2);

	try
	{
		std::vector<int>::iterator it = easyfind(v, 8);
		std::cout << "Found " << *it << " at index "
				  << (it - v.begin()) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	try
	{
		easyfind(v, 7);
		std::cout << "Found 7 (unexpected)" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::list<int> l;
	l.push_back(42);
	l.push_back(21);
	l.push_back(84);

	try
	{
		std::list<int>::iterator it = easyfind(l, 21);
		std::cout << "Found " << *it << " in the list" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}

	return 0;
}
