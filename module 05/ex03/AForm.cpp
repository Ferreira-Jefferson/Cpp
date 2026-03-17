#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default"), _signed(false), _signGrade(150), _execGrade(150) {}

AForm::AForm(std::string const& name, int signGrade, int execGrade)
	: _name(name), _signed(false), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const& src)
	: _name(src._name), _signed(src._signed),
	  _signGrade(src._signGrade), _execGrade(src._execGrade) {}

AForm::~AForm() {}

AForm& AForm::operator=(AForm const& rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

std::string const& AForm::getName() const
{
	return _name;
}

bool AForm::getSigned() const
{
	return _signed;
}

int AForm::getSignGrade() const
{
	return _signGrade;
}

int AForm::getExecGrade() const
{
	return _execGrade;
}

void AForm::beSigned(Bureaucrat const& b)
{
	if (b.getGrade() > _signGrade)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _execGrade)
		throw GradeTooLowException();
	doExecute();
}

char const* AForm::GradeTooHighException::what() const throw()
{
	return "grade is too high";
}

char const* AForm::GradeTooLowException::what() const throw()
{
	return "grade is too low";
}

char const* AForm::FormNotSignedException::what() const throw()
{
	return "form is not signed";
}

std::ostream& operator<<(std::ostream& os, AForm const& f)
{
	os << f.getName() << ", form signed: " << f.getSigned()
	   << ", sign grade: " << f.getSignGrade()
	   << ", exec grade: " << f.getExecGrade();
	return os;
}
