/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 06:12:53 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/12 08:04:28 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern()
{
	std::cout << std::setw(25) << "[Intern] " << "create!!" << std::endl;
}

Intern::Intern(const Intern& ref)
{
	(void)ref;
	std::cout << std::setw(25) << "[Intern] " << "copy!!" << std::endl;
}

Intern::~Intern()
{
	std::cout << std::setw(25) << "[Intern] " << "delete!!" << std::endl;
}

Intern&	Intern::operator=(const Intern& ref)
{
	(void)ref;
	std::cout << std::setw(25) << "[Intern] " << "operator=!!" << std::endl;
	return (*this);
}

const char*	Intern::Exception::what() const throw() { return ("the Intern Exceptoin"); }


AForm	*new_shrubbery_creation_form(std::string target) { return (new ShrubberyCreationForm(target)); }
AForm	*new_presidential_pardon_form(std::string target) { return (new PresidentialPardonForm(target)); }
AForm	*new_robotomy_request_form(std::string target) { return (new RobotomyRequestForm(target)); }

AForm	*Intern::makeForm(std::string name, std::string target)
{
	std::string	msg[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm		*(*fct[3])(std::string target) = { new_shrubbery_creation_form, new_robotomy_request_form, new_presidential_pardon_form};
	AForm		*ret = NULL;
	
	for (int i = 0; i < 3; i++)
	{
		if (name == msg[i])
			ret = fct[i](target);
	}
	if (ret)
		std::cout << std::setw(25) << "[Intern] " << "Intern creates " << *ret << std::endl;
	else
		throw (Intern::Exception());
	return (ret);
}
