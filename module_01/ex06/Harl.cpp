/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:07:28 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/02 21:17:02 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include <Harl.hpp>


Harl::Harl() {}

Harl::~Harl() {}


void	Harl::debug( void )
{
	std::cout
		<< "[DEBUG]\n"
		<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger.\n"
		<< "I really do!" 
		<< std::endl;
}

void	Harl::info( void )
{
	std::cout
		<< "[INFO]\n"
		<< "I cannot believe adding extra bacon costs more money.\n"
		<< "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
		<< std::endl;
}

void	Harl::warning( void )
{
	std::cout 
		<< "[WARNING]\n"
		<< "I think I deserve to have some extra bacon for free.\n"
		<< "I’ve been coming for years whereas you started working here since last month."
		<< std::endl;
}

void	Harl::error( void )
{
	std::cout 
		<< "[ERROR]\n"
		<< "This is unacceptable! I want to speak to the manager now."
		<< std::endl;
}

void	Harl::complain( std::string level )
{
	std::string	str_level[Harl::END] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	int			num_level;

	f funtion[Harl::END] = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error
	};
	num_level = std::find(str_level, str_level + Harl::END, level) - str_level;
	if (num_level != Harl::END)
	{	
		while (num_level < Harl::END)
		{
			(this->*(funtion[num_level++]))();
			std::cout << std::endl;
		}
		return ;
	}
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
	return ;
}
