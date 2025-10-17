#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "../include/AForm.hpp"
# include <string>
# include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
		const std::string _target;

	public:
		//OCF
		explicit ShrubberyCreationForm(const std::string& target);
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		~ShrubberyCreationForm();

		//Execute
		void execute(Bureaucrat const& executor) const;
};

#endif // SHRUBBERYCREATIONFORM_HPP
