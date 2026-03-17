#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm()
	: _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150) {}

AForm::AForm(std::string const& name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (_gradeToSign < 1 || _gradeToExec < 1)
		throw GradeTooHighException();
	if (_gradeToSign > 150 || _gradeToExec > 150)
		throw GradeTooLowException();
}

AForm::AForm(AForm const& src)
	: _name(src._name), _signed(src._signed),
	  _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec) {}

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

bool AForm::isSigned() const
{
	return _signed;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExec() const
{
	return _gradeToExec;
}

void AForm::beSigned(Bureaucrat const& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!_signed)
		throw FormNotSignedException();
	if (executor.getGrade() > _gradeToExec)
		throw GradeTooLowException();
	executeAction();
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
	os << "Form " << f.getName()
	   << ", signed: " << (f.isSigned() ? "yes" : "no")
	   << ", grade to sign: " << f.getGradeToSign()
	   << ", grade to exec: " << f.getGradeToExec();
	return os;
}
