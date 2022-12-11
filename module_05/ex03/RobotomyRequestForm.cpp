/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:51:04 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/12 07:27:22 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm():
	AForm("robotomy request", 72, 45),
	_target("Default")
{
	std::cout 
		<< std::setw(25) << "[RobotomyRequestForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "create!!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target):
	AForm("robotomy request", 72, 45),
	_target(target)
{
	std::cout 
		<< std::setw(25) << "[RobotomyRequestForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "create!!" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& ref):
	AForm(ref.get_name(), ref.get_grad_to_sign(), ref.get_grad_to_execute()),
	_target(ref.get_target())
{
	std::cout 
		<< std::setw(25) << "[RobotomyRequestForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "copy!!" << std::endl;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout 
		<< std::setw(25) << "[RobotomyRequestForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "delete!!" << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& ref)
{
	this->set_signed(ref.get_signed());
	this->set_target(ref.get_target());
	std::cout 
		<< std::setw(25) << "[RobotomyRequestForm] " 
		<< std::setw(20) << this->_target << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "operator=!!" << std::endl;
	return (*this);
}

std::string	RobotomyRequestForm::get_target() const { return (this->_target); }
void	RobotomyRequestForm::set_target(std::string target) { this->_target = target; }

void	RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	if (!this->get_signed())
		throw (AForm::SignedException());
	else if (executor.getGrade() > this->get_grad_to_execute())
		throw (AForm::GradeTooLowException());
	else
	{
		if (std::rand() % 2)
		{
			std::cout << std::setw(15)
				<< "[RobotomyRequestForm] "
				<< "rizzz~~ bzzzzzz~~!! "
				<< this->get_target()
				<< " has been robotomized successfully"
				<< std::endl;
		}
		else
		{
			std::cout << std::setw(15)
				<< "[RobotomyRequestForm] "
				<< "rizzz~~ bzzzzzz~~!! "
				<< this->get_target()
				<< " has been robotomy failed."
				<< std::endl;
		}
	}
}
