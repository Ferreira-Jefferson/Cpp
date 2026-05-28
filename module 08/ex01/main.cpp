#include "Span.hpp"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int main()
{
	// Subject example
	{
		Span sp = Span(5);
		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}

	// Overflow on addNumber
	{
		Span sp(2);
		sp.addNumber(1);
		sp.addNumber(2);
		try
		{
			sp.addNumber(3);
		}
		catch (std::exception &e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}

	// Not enough numbers
	{
		Span sp(5);
		sp.addNumber(42);
		try
		{
			sp.shortestSpan();
		}
		catch (std::exception &e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}

	// Range filling + large test (>= 10000)
	{
		const unsigned int N = 25000;
		Span sp(N);

		std::srand(static_cast<unsigned int>(std::time(0)));
		std::vector<int> values;
		values.reserve(N);
		for (unsigned int i = 0; i < N; ++i)
			values.push_back(std::rand());

		sp.addRange(values.begin(), values.end());

		std::cout << "Filled " << N << " numbers via iterator range" << std::endl;
		std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
		std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;

		try
		{
			sp.addNumber(0);
		}
		catch (std::exception &e)
		{
			std::cout << "Caught: " << e.what() << std::endl;
		}
	}

	return 0;
}
