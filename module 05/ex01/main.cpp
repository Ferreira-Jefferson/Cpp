#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "=== Form creation with valid grades ===" << std::endl;
	try
	{
		Form a("Tax Form", 50, 25);
		std::cout << a << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Form creation with grade too high ===" << std::endl;
	try
	{
		Form b("Bad Form", 0, 25);
		std::cout << b << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Form creation with grade too low ===" << std::endl;
	try
	{
		Form c("Bad Form", 50, 151);
		std::cout << c << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Signing with sufficient grade ===" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 1);
		Form taxForm("Tax Form", 50, 25);
		std::cout << bob << std::endl;
		std::cout << taxForm << std::endl;
		bob.signForm(taxForm);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== Signing with insufficient grade ===" << std::endl;
	try
	{
		Bureaucrat jim("Jim", 100);
		Form taxForm("Tax Form", 50, 25);
		std::cout << jim << std::endl;
		std::cout << taxForm << std::endl;
		jim.signForm(taxForm);
		std::cout << taxForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << std::endl << "=== beSigned direct call throwing exception ===" << std::endl;
	try
	{
		Bureaucrat low("Lowbie", 150);
		Form secret("Secret File", 1, 1);
		secret.beSigned(low);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
