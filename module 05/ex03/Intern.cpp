#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}

Intern::Intern(Intern const& src)
{
	(void)src;
}

Intern::~Intern() {}

Intern& Intern::operator=(Intern const& rhs)
{
	(void)rhs;
	return *this;
}

AForm* Intern::createShrubbery(std::string const& target)
{
	return new ShrubberyCreationForm(target);
}

AForm* Intern::createRobotomy(std::string const& target)
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::createPresidential(std::string const& target)
{
	return new PresidentialPardonForm(target);
}

typedef AForm* (*FormCreator)(std::string const&);

struct FormEntry
{
	std::string	name;
	FormCreator	creator;
};

AForm* Intern::makeForm(std::string const& formName, std::string const& target)
{
	static FormEntry forms[] = {
		{"shrubbery creation", &Intern::createShrubbery},
		{"robotomy request", &Intern::createRobotomy},
		{"presidential pardon", &Intern::createPresidential}
	};
	static int const numForms = sizeof(forms) / sizeof(forms[0]);

	for (int i = 0; i < numForms; i++)
	{
		if (forms[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].creator(target);
		}
	}
	std::cerr << "Intern cannot create \"" << formName
			  << "\": unknown form name" << std::endl;
	return NULL;
}
