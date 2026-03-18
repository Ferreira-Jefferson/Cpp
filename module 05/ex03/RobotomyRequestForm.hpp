#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string const& target);
		RobotomyRequestForm(RobotomyRequestForm const& src);
		~RobotomyRequestForm();

		RobotomyRequestForm& operator=(RobotomyRequestForm const& rhs);

		std::string const&	getTarget() const;

	protected:
		void	doExecute() const;

	private:
		std::string	_target;
};

#endif
