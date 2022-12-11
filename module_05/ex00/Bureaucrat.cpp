/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:45:13 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/08 22:42:34 by kyoulee          ###   ########.fr       */
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
	std::cout << std::setw(15) << "[Bureaucrat] " << std::setw(15) << this->_name << "[" << this->_grade << "]" << " create!!" << std::endl;
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
		std::cout << std::setw(15) << "[Bureaucrat] " << this->_name << "[" << this->_grade << "]" << " create!!" << std::endl;
	}
}

Bureaucrat::Bureaucrat(const Bureaucrat& ref):
	_name(ref._name),
	_grade(ref._grade)
{
	std::cout << std::setw(15) << "[Bureaucrat] " << this->_name << "[" << this->_grade << "]" << " copy!!" << std::endl;
}

Bureaucrat::~Bureaucrat()
{
	std::cout << std::setw(15) << "[Bureaucrat] " << this->_name << "[" << this->_grade << "]" << " delete!!" << std::endl;
}

Bureaucrat&	Bureaucrat::operator=(const Bureaucrat& ref)
{
	this->_grade = ref._grade;
	std::cout << std::setw(15) << "[Bureaucrat] " << this->_name << "[" << this->_grade << "]" << " operator=!!" << std::endl;
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
