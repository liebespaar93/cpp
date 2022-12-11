/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:47:06 by dpoveda-          #+#    #+#             */
/*   Updated: 2022/12/12 07:39:05 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

#include <iostream>
#include <iomanip>

int	main(void)
{
    std::cout << std::setfill(' ') << std::left;
	std::srand(std::time(0)); // common practice to seed the pseudo-random number generator

	// Constructors
	std::cout << std::endl;
	std::cout << "CONSTRUCTING:" << std::endl;
	std::cout << "----------------------------" << std::endl;

	Intern	intern;
	AForm	*robo_form;
	AForm	*shrub_form;
	AForm	*president_form;
	AForm	*unknown_form;
	std::cout << std::endl << std::endl;
	//-----------------------------------------------------


	std::cout << "INTERN TESTS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	// Robo:
	std::cout << "ROBO:" << std::endl;
	robo_form = intern.makeForm("robotomy request", "robo");
	std::cout << std::setw(25) << "[Main]" << " was just created \n" << *robo_form << std::endl << std::endl;
	std::cout << std::endl;

	// President:
	std::cout << "PRESIDENT:" << std::endl;
	president_form = intern.makeForm("presidential pardon", "president");
	std::cout << std::setw(25) << "[Main]" << " was just created \n" << *president_form << std::endl << std::endl;
	std::cout << std::endl;

	// Shrub:
	std::cout << "SHRUB:" << std::endl;
	shrub_form = intern.makeForm("shrubbery creation", "shrub");
	std::cout << std::setw(25) << "[Main]" << " was just created \n" << *shrub_form << std::endl << std::endl;
	std::cout << std::endl;

	// Unknown:
	std::cout << "UNKNOWN:" << std::endl;
	try
	{
		unknown_form = intern.makeForm("driving licence", "drive");
		std::cout << std::setw(25) << "[Main]" << " was just created \n" << *unknown_form << std::endl << std::endl;
	}
	catch (Intern::Exception &e)
	{
		std::cout << e.what() << std::endl << std::endl;
	}
	std::cout << std::endl;
	std::cout << "DESTRUCTORS:" << std::endl;
	std::cout << "----------------------------" << std::endl;
	
	delete (robo_form);
	delete (shrub_form);
	delete (president_form);
	//delete (unknown_form);
	return (0);
}
