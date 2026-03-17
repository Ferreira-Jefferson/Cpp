#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "=== Normal creation ===" << std::endl;
	try
	{
		Bureaucrat a("Alice", 42);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Grade too high (0) ===" << std::endl;
	try
	{
		Bureaucrat b("Bob", 0);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Grade too high (-5) ===" << std::endl;
	try
	{
		Bureaucrat c("Charlie", -5);
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Grade too low (151) ===" << std::endl;
	try
	{
		Bureaucrat d("Dave", 151);
		std::cout << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Increment and decrement ===" << std::endl;
	try
	{
		Bureaucrat e("Eve", 5);
		std::cout << e << std::endl;
		e.incrementGrade();
		std::cout << "After increment: " << e << std::endl;
		e.decrementGrade();
		std::cout << "After decrement: " << e << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Increment past 1 ===" << std::endl;
	try
	{
		Bureaucrat f("Frank", 1);
		std::cout << f << std::endl;
		f.incrementGrade();
		std::cout << f << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Decrement past 150 ===" << std::endl;
	try
	{
		Bureaucrat g("Grace", 150);
		std::cout << g << std::endl;
		g.decrementGrade();
		std::cout << g << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Copy and assignment ===" << std::endl;
	try
	{
		Bureaucrat h("Hank", 50);
		Bureaucrat i(h);
		std::cout << "Original: " << h << std::endl;
		std::cout << "Copy:     " << i << std::endl;
		Bureaucrat j("Jane", 100);
		j = h;
		std::cout << "Assigned: " << j << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
