#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void) : _name("Default"), _signed(false), _gradeToSign(150), _gradeToExec(150)
{
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExec)
	: _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec)
{
	if (gradeToSign < 1 || gradeToExec < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExec > 150)
		throw GradeTooLowException();
}

Form::Form(const Form &src)
	: _name(src._name), _signed(src._signed),
	  _gradeToSign(src._gradeToSign), _gradeToExec(src._gradeToExec)
{
}

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
		_signed = rhs._signed;
	return *this;
}

Form::~Form(void)
{
}

const std::string &Form::getName(void) const
{
	return _name;
}

bool Form::getSigned(void) const
{
	return _signed;
}

int Form::getGradeToSign(void) const
{
	return _gradeToSign;
}

int Form::getGradeToExec(void) const
{
	return _gradeToExec;
}

void Form::beSigned(const Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_signed = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "Grade is too high";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Grade is too low";
}

std::ostream &operator<<(std::ostream &out, const Form &f)
{
	out << "Form " << f.getName()
		<< ", signed: " << (f.getSigned() ? "yes" : "no")
		<< ", grade to sign: " << f.getGradeToSign()
		<< ", grade to exec: " << f.getGradeToExec()
		<< ".";
	return out;
}
