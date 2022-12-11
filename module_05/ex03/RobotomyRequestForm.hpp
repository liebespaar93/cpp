#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>

# include "AForm.hpp"

class RobotomyRequestForm: public AForm
{
private:
	/* data */
	std::string	_target;

public:
	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm& ref);
	~RobotomyRequestForm();

	RobotomyRequestForm&	operator=(const RobotomyRequestForm& ref);

	std::string	get_target() const;
	void	set_target(std::string target);

	void	execute(Bureaucrat const & executor) const;
};

#endif
