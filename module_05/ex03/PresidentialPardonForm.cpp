/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:48:37 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/12 04:32:07 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():
	AForm("presidential pardon", 25, 5),
	_target("Default")
{
	std::cout 
		<< std::setw(25) << "[PresidentialPardonForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "create!!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target):
	AForm("presidential pardon", 25, 5),
	_target(target)
{
	std::cout 
		<< std::setw(25) << "[PresidentialPardonForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "create!!" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref):
	AForm(ref.get_name(), ref.get_signed(), ref.get_grad_to_execute()),
	_target(ref.get_target())
{
	std::cout 
		<< std::setw(25) << "[PresidentialPardonForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "copy!!" << std::endl;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout 
		<< std::setw(25) << "[PresidentialPardonForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "delete!!" << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	this->set_signed(ref.get_signed());
	this->set_target(ref.get_target());
	std::cout 
		<< std::setw(25) << "[PresidentialPardonForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "operator=!!" << std::endl;
	return (*this);
}

std::string	PresidentialPardonForm::get_target() const { return (this->_target); }
void	PresidentialPardonForm::set_target(std::string target) { this->_target = target; }

void	PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	if (!this->get_signed())
		throw (AForm::SignedException());
	else if (executor.getGrade() > this->get_grad_to_execute())
		throw (AForm::GradeTooLowException());
	else
	{
		std::cout << std::setw(15)
			<< "[PresidentialPardonForm] "
			<< "Informs that "
			<< this->get_target()
			<< " has been pardoned by Zaphod Beeblebrox."
			<< std::endl;
	}
}
