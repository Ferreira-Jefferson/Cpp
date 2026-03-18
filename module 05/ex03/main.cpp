#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <cstdlib>
#include <ctime>

int main()
{
	std::srand(std::time(NULL));

	Intern	someRandomIntern;

	std::cout << "=== Subject example: robotomy request ===" << std::endl;
	AForm* rrf = someRandomIntern.makeForm("robotomy request", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	std::cout << std::endl;
	std::cout << "=== Shrubbery creation ===" << std::endl;
	AForm* scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
	if (scf)
	{
		std::cout << *scf << std::endl;
		delete scf;
	}

	std::cout << std::endl;
	std::cout << "=== Presidential pardon ===" << std::endl;
	AForm* ppf = someRandomIntern.makeForm("presidential pardon", "Arthur");
	if (ppf)
	{
		std::cout << *ppf << std::endl;
		delete ppf;
	}

	std::cout << std::endl;
	std::cout << "=== Invalid form name ===" << std::endl;
	AForm* bad = someRandomIntern.makeForm("nonexistent form", "Nobody");
	if (!bad)
		std::cout << "Form creation returned NULL as expected" << std::endl;

	std::cout << std::endl;
	std::cout << "=== Sign and execute a form ===" << std::endl;
	Bureaucrat boss("Boss", 1);
	AForm* form = someRandomIntern.makeForm("presidential pardon", "Trillian");
	if (form)
	{
		boss.signForm(*form);
		boss.executeForm(*form);
		delete form;
	}

	return 0;
}
