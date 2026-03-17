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
	AForm(std::string const& name, int signGrade, int execGrade);
	AForm(AForm const& src);
	virtual ~AForm();

	AForm& operator=(AForm const& rhs);

	std::string const&	getName() const;
	bool				getSigned() const;
	int					getSignGrade() const;
	int					getExecGrade() const;

	void			beSigned(Bureaucrat const& b);
	void			execute(Bureaucrat const& executor) const;

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
	virtual void	doExecute() const = 0;

private:
	std::string const	_name;
	bool				_signed;
	int const			_signGrade;
	int const			_execGrade;
};

std::ostream& operator<<(std::ostream& os, AForm const& f);

#endif
