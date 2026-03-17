#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class AForm;

class Bureaucrat
{
public:
	Bureaucrat();
	Bureaucrat(std::string const& name, int grade);
	Bureaucrat(Bureaucrat const& src);
	~Bureaucrat();

	Bureaucrat& operator=(Bureaucrat const& rhs);

	std::string const&	getName() const;
	int					getGrade() const;

	void	incrementGrade();
	void	decrementGrade();

	void	signForm(AForm& form);
	void	executeForm(AForm const& form) const;

	class GradeTooHighException : public std::exception
	{
	public:
		char const* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		char const* what() const throw();
	};

private:
	std::string const	_name;
	int					_grade;
};

std::ostream& operator<<(std::ostream& os, Bureaucrat const& b);

#endif
