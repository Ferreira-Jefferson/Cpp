#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	std::cout << "===== SHRUBBERY CREATION FORM =====" << std::endl;
	try
	{
		Bureaucrat bob("Bob", 1);
		ShrubberyCreationForm shrub("home");

		std::cout << shrub << std::endl;

		std::cout << "\n-- Try executing unsigned form --" << std::endl;
		bob.executeForm(shrub);

		std::cout << "\n-- Sign and execute --" << std::endl;
		bob.signForm(shrub);
		bob.executeForm(shrub);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n-- Try with low grade bureaucrat --" << std::endl;
	try
	{
		Bureaucrat intern("Intern", 150);
		ShrubberyCreationForm shrub2("garden");

		intern.signForm(shrub2);
		intern.executeForm(shrub2);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== ROBOTOMY REQUEST FORM =====" << std::endl;
	try
	{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robo("Bender");

		std::cout << robo << std::endl;

		std::cout << "\n-- Try executing unsigned form --" << std::endl;
		boss.executeForm(robo);

		std::cout << "\n-- Sign and execute --" << std::endl;
		boss.signForm(robo);
		boss.executeForm(robo);
		boss.executeForm(robo);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n-- Try with low grade bureaucrat --" << std::endl;
	try
	{
		Bureaucrat clerk("Clerk", 100);
		RobotomyRequestForm robo2("Target");

		clerk.signForm(robo2);
		clerk.executeForm(robo2);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n===== PRESIDENTIAL PARDON FORM =====" << std::endl;
	try
	{
		Bureaucrat president("President", 1);
		PresidentialPardonForm pardon("Arthur Dent");

		std::cout << pardon << std::endl;

		std::cout << "\n-- Try executing unsigned form --" << std::endl;
		president.executeForm(pardon);

		std::cout << "\n-- Sign and execute --" << std::endl;
		president.signForm(pardon);
		president.executeForm(pardon);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\n-- Try with low grade bureaucrat --" << std::endl;
	try
	{
		Bureaucrat lowGrade("LowGrade", 30);
		PresidentialPardonForm pardon2("Ford Prefect");

		lowGrade.signForm(pardon2);
		lowGrade.executeForm(pardon2);
	}
	catch (std::exception& e)
	{
		std::cerr << "Exception: " << e.what() << std::endl;
	}

	return 0;
}
