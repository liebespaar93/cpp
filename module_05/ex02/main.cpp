/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:47:06 by dpoveda-          #+#    #+#             */
/*   Updated: 2023/01/25 02:12:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
    std::cout << std::setfill(' ') << std::left;
	std::srand(std::time(0)); // common practice to seed the pseudo-random number generator

	// Constructors
	std::cout << std::endl;
	std::cout << "CONSTRUCTING:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Bureaucrat				A("A", 1);
	Bureaucrat				B("B", 142);
	ShrubberyCreationForm	shrub("shrub");
	RobotomyRequestForm		robo("robo");
	PresidentialPardonForm	president("president");
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	// Executing
	// ShrubberyCreationForm : sign 145, exec 137
	// RobotomyRequestForm sign 72, exec 45
	// PresidentialPardonForm sign 25, exec 5

	std::cout << "SHRUBBERY CREATION FORM:" << std::endl;
	std::cout << "----------------------------" << std::endl;


	std::cout << std::endl << "[UNSIGNED]" << std::endl;
	A.executeForm(shrub);
	shrub.beSigned(A);
	std::cout << std::endl;


	std::cout << std::endl << "[SIGNED]" << std::endl;
	A.executeForm(shrub);
	std::cout << std::endl;


	std::cout << std::endl << "[GRADE TO EXE TOO LOW]" << std::endl;
	A.signForm(shrub);
	B.signForm(shrub);
	B.executeForm(shrub);
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << "ROBOTOMY REQUEST FORM:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	std::cout << std::endl << "[UNSIGNED]" << std::endl;
	A.executeForm(robo);
	robo.beSigned(A);


	std::cout << std::endl << "[SIGNED (50% failure chance)]" << std::endl;
	A.executeForm(robo);
	A.executeForm(robo);
	A.executeForm(robo);
	A.executeForm(robo);
	A.executeForm(robo);
	std::cout << std::endl;


	std::cout << std::endl << "[GRADE TO EXE TOO LOW]" << std::endl;
	B.executeForm(robo);
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << "PRESIDENTIAL PARDON FORM:" << std::endl;
	std::cout << "----------------------------" << std::endl;


	std::cout << std::endl << "[UNSIGNED]" << std::endl;
	A.executeForm(president);
	president.beSigned(A);


	std::cout << std::endl << "[SIGNED]" << std::endl;
	A.executeForm(president);
	std::cout << std::endl;


	std::cout << std::endl << "[GRADE TO EXE TOO LOW]" << std::endl;
	B.executeForm(president);
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << std::endl;
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	return (0);
}
