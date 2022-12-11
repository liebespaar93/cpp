/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:45:13 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/12 07:27:04 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <exception>

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat():
	_name("Defualt"),
	_grade(this->_max_grade)
{
	std::cout << std::setw(25) << "[Bureaucrat] " << std::setw(15) << this->_name << "[" << this->_grade << "]" << " create!!" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade):
	_name(name)
{
	if (grade > _max_grade)
		throw (Bureaucrat::GradeTooLowException());
	else if (grade < _min_grade)
		throw (Bureaucrat::GradeTooHighException());
	else
	{
		this->_grade = grade;
		std::cout << std::setw(25) << "[Bureaucrat] " << this->_name << "[" << this->_grade << "]" << " create!!" << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref):
	_name(ref._name),
	_grade(ref._grade)
{
	std::cout << std::setw(25) << "[Bureaucrat] " << this->_name << "[" << this->_grade << "]" << " copy!!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << std::setw(25) << "[Bureaucrat] " << this->_name << "[" << this->_grade << "]" << " delete!!" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& ref)
{
	this->_grade = ref._grade;
	std::cout << std::setw(25) << "[Bureaucrat] " << this->_name << "[" << this->_grade << "]" << " operator=!!" << std::endl;
	return (*this);
}

void	Bureaucrat::increment()
{
	std::cout << std::setw(15) << "[Bureaucrat] " << this->_name << "[" << this->_grade << "]" <<  " Increment grade " << " by 1" << std::endl;
	if (this->_grade - 1 < 1)
		throw (Bureaucrat::GradeTooHighException());
	else
		this->_grade--;
}

void	Bureaucrat::decrement()
{
	std::cout << std::setw(15) << "[Bureaucrat] " << this->_name << "[" << this->_grade << "]" << " Decrementing grade " << " by 1" << std::endl;
	if (this->_grade + 1 > 150)
		throw (Bureaucrat::GradeTooLowException());
	else
		this->_grade++;
}

const std::string&	Bureaucrat::getName() const { return (this->_name); }
int	Bureaucrat::getGrade() const { return (this->_grade); }

const char* Bureaucrat::GradeTooHighException::what() const throw() { return ("GradeTooHighException get a grade < 1!"); }
const char* Bureaucrat::GradeTooLowException::what() const throw() { return ("GradeTooLowException get a grade > 150!"); }

std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref)
{
	os << ref.getName() << ", bureaucrat grade " << ref.getGrade() << ".";
	return (os);
}

/* ============= ex01 ============= */

void	Bureaucrat::signForm(AForm& ref)
{
	try
	{
		ref.beSigned(*this);
		std::cout << std::setw(25) << "[Bureaucrat] " << this->_name << "["<< this->_grade << "]" << " signed " << ref.get_name() << std::endl;
	}
	catch (AForm::GradeTooLowException &e)
	{
		std::cout << std::setw(25) << "[Bureaucrat] " << this->_name << "["<< this->_grade << "]" << " couldn’t sign " << ref.get_name() << " because " << e.what() << std::endl;
	}
}

/* ============= ex02 ============= */

void Bureaucrat::executeForm(AForm const & form)
{
	try
	{
		form.execute(*this);
		std::cout
			<< std::setw(25) << "[Bureaucrat] "
			<< this->getName() << "[" << this->getGrade() << "] "
			<< " executed "
			<< form.get_name() << "[" << form.get_grad_to_execute() << "] "
			<< "signed [" << form.get_signed() << "] "
			<< std::endl;
	}
	catch (std::exception &e)
	{
		std::cout
			<< std::setw(25) << "[Bureaucrat] "
			<< this->getName() << "[" << this->getGrade() << "] "
			<< "not execute " 
			<< form.get_name() << "[" << form.get_grad_to_execute() << "] "
			<< "signed [" << form.get_signed() << "] "
			<< std::endl;
		std::cout << e.what() << std::endl;
	}
}
