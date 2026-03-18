#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string const& target);
		ShrubberyCreationForm(ShrubberyCreationForm const& src);
		~ShrubberyCreationForm();

		ShrubberyCreationForm& operator=(ShrubberyCreationForm const& rhs);

	protected:
		void	executeAction() const;

	private:
		std::string	_target;
};

#endif
