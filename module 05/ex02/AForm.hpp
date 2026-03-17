#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>
# include <stdexcept>

class Bureaucrat;

class AForm
{
public:
	AForm();
	AForm(std::string const& name, int gradeToSign, int gradeToExec);
	AForm(AForm const& src);
	virtual ~AForm();

	AForm& operator=(AForm const& rhs);

	std::string const&	getName() const;
	bool				isSigned() const;
	int					getGradeToSign() const;
	int					getGradeToExec() const;

	void	beSigned(Bureaucrat const& bureaucrat);
	void	execute(Bureaucrat const& executor) const;

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

	class FormNotSignedException : public std::exception
	{
	public:
		char const* what() const throw();
	};

protected:
	virtual void	executeAction() const = 0;

private:
	std::string const	_name;
	bool				_signed;
	int const			_gradeToSign;
	int const			_gradeToExec;
};

std::ostream& operator<<(std::ostream& os, AForm const& f);

#endif
