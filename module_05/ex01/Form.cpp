/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 15:44:40 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/18 08:54:58 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Form.hpp"

Form::Form():
	_name("Default"),
	_grade_to_sign(150),
	_grade_to_execute(150),
	_signed(0)
{
	std::cout << std::setw(15) << "[Form] " << "create!!" << std::endl;
}

Form::Form(std::string name, int grade_to_sign, int grade_to_execute):
	_name(name),
	_grade_to_sign(grade_to_sign),
	_grade_to_execute(grade_to_execute),
	_signed(0)
{
	std::cout << std::setw(15) << "[Form] " << "create!!" << std::endl;
}

Form::Form(const Form& ref):
	_name(ref._name),
	_grade_to_sign(ref._grade_to_sign),
	_grade_to_execute(ref._grade_to_execute),
	_signed(ref._signed)
{
	std::cout << std::setw(15) << "[Form] " << "copy!!" << std::endl;
}

Form::~Form()
{
	std::cout << std::setw(15) << "[Form] " << "delete!!" << std::endl;
}

Form&	Form::operator=(const Form& ref)
{
	const_cast<std::string&>(this->_name) = ref._name;
	const_cast<int&>(this->_grade_to_sign) = ref._grade_to_sign;
	const_cast<int&>(this->_grade_to_execute) = ref._grade_to_execute;
	this->_signed = ref._signed;
	std::cout << std::setw(15) << "[Form] " << "operator=!!" << std::endl;
	return (*this);
}

const	std::string&	Form::get_name() const { return (this->_name); }
int	Form::get_grad_to_sign() const { return (this->_grade_to_sign); }
int	Form::get_grad_to_execute() const { return (this->_grade_to_execute); }
bool	Form::get_signed() const { return (this->_signed); }

void	Form::set_signed(bool sign) { this->_signed = sign; }

void Form::beSigned(const Bureaucrat& ref)
{
	if (ref.getGrade() <= this->get_grad_to_sign())
	{
		this->set_signed(true);
		std::cout <<  ref.getName() << " has signed " << this->_name << std::endl;
	}
	else
	{
		std::cout << ref.getName() << " can't sign " << this->_name << std::endl;
		throw Form::GradeTooLowException();
	}
}

const char*	Form::GradeTooLowException::what() const throw() { return ("the grade is too low"); }
const char*	Form::GradeTooHighException::what() const throw() { return ("the grade is too high"); }

std::ostream& operator<<(std::ostream& os, const Form& ref)
{
	os << "Form " << ref.get_name()
		<< ", status: " << (ref.get_signed() ? "signed" : "not signed")
		<< ", sign grade: " << ref.get_grad_to_sign()
		<< ", execute grade: " << ref.get_grad_to_execute()
		<< std::endl;
	return os;
}
