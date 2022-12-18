/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:44:34 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/18 09:36:22 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "AForm.hpp"

AForm::AForm():
	_name("Default"),
	_grade_to_sign(150),
	_grade_to_execute(150),
	_signed(0)
{
	std::cout 
		<< std::setw(25) << "[AForm] " 
		<< std::setw(15) << this->_name << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "create!!" << std::endl;
}

AForm::AForm(std::string name, int grade_to_sign, int grade_to_execute):
	_name(name),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute),
	_signed(0)
{
	std::cout 
		<< std::setw(25) << "[AForm] " 
		<< std::setw(20) << this->_name << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "create!!" << std::endl;
}

AForm::AForm(const AForm& ref):
	_name(ref._name),
	_grade_to_sign(ref._grade_to_sign),
	_grade_to_execute(ref._grade_to_execute),
	_signed(ref._signed)
{
	std::cout 
		<< std::setw(25) << "[AForm] " 
		<< std::setw(20) << this->_name << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "copy!!" << std::endl;
}

AForm::~AForm()
{
	std::cout 
		<< std::setw(25) << "[AForm] " 
		<< std::setw(20) << this->_name << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "delete!!" << std::endl;
}

AForm&	AForm::operator=(const AForm& ref)
{
	const_cast<std::string&>(this->_name) = ref._name;
	const_cast<int&>(this->_grade_to_sign) = ref._grade_to_sign;
	const_cast<int&>(this->_grade_to_execute) = ref._grade_to_execute;
	this->_signed = ref._signed;
	std::cout 
		<< std::setw(25) << "[AForm] " 
		<< std::setw(20) << this->_name << " "
		<< "sign : [" << this->get_grad_to_sign() << "] "
		<< "execute : [" << this->get_grad_to_execute() << "] "
		<< "operator=!!" << std::endl;
	return (*this);
}

const std::string&	AForm::get_name() const { return (this->_name); }
int					AForm::get_grad_to_sign() const { return (this->_grade_to_sign); }
int					AForm::get_grad_to_execute() const { return (this->_grade_to_execute); }
bool				AForm::get_signed() const { return (this->_signed); }

void	AForm::set_signed(bool sign) { this->_signed = sign; }

void AForm::beSigned(const Bureaucrat& ref)
{
	if (ref.getGrade() <= this->get_grad_to_sign())
	{
		this->set_signed(true);
		std::cout << std::setw(25) << "[AForm] " <<  ref.getName() << " has signed " << this->_name << std::endl;
	}
	else
	{
		std::cout << std::setw(25) << "[AForm] " << ref.getName() << " can't sign " << this->_name << std::endl;
		throw AForm::GradeTooLowException();
	}
}

const char*	AForm::GradeTooLowException::what() const throw() { return ("the grade is too low"); }
const char*	AForm::GradeTooHighException::what() const throw() { return ("the grade is too high"); }

std::ostream& operator<<(std::ostream& os, const AForm& ref)
{
	os << "AForm " << ref.get_name()
		<< ", status: " << (ref.get_signed() ? "signed" : "not signed")
		<< ", sign grade: " << ref.get_grad_to_sign()
		<< ", execute grade: " << ref.get_grad_to_execute()
		<< std::endl;
	return os;
}

/* ============= ex02 ============= */

const char*	AForm::SignedException::what() const throw() { return ("the signed is false"); }

void	AForm::execute(Bureaucrat const & executor) const
{
	if (this->get_signed() == false)
		throw (AForm::SignedException());
	else if (executor.getGrade() > this->get_grad_to_execute())
		throw (AForm::GradeTooLowException());
	else
		std::cout << this->_name << " was pardonned by Zafod Beeblebrox\n";
}
