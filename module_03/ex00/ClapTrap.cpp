/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:51:03 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/21 14:07:11 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"

ClapTrap::ClapTrap():
	_name("Default"),
	_hit_point(10),
	_energy_points(10),
	_attack_damage(0) 
{
	std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "ClapTrap created!!" << std::endl;
}

ClapTrap::ClapTrap(std::string name):
	_name(name),
	_hit_point(10),
	_energy_points(10),
	_attack_damage(0) 
{
	std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "ClapTrap created!!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref):
	_name(ref._name),
	_hit_point(ref._hit_point),
	_energy_points(ref._energy_points),
	_attack_damage(ref._attack_damage) 
{
	std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "ClapTrap copy!!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "ClapTrap destroy!!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& ref)
{
	std::string	old_name;

	old_name = this->_name;
	this->_name = ref._name;
	this->_hit_point = ref._hit_point;
	this->_energy_points = ref._energy_points;
	this->_attack_damage = ref._attack_damage;

	std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << old_name << "operator = " << ref._name << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->_energy_points)
		std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "not enough energy!! (Attack Cancel)" << std::endl;
	else if (!this->_hit_point)
		std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "dead!! (Attack Cancel)" << std::endl;
	else 
	{
		this->_energy_points--;
		std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "Attack !! " << target << " hit " << this->_attack_damage << " damage"<< std::endl;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->_energy_points)
		std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "not enough energy!! (takeDamage Cancel)" << std::endl;
	else if (!this->_hit_point)
		std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "dead!! (takeDamage Cancel)" << std::endl;
	else
	{
		this->_energy_points--;

		if (this->_hit_point > amount)
		{
			this->_hit_point -= amount;
			std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "get " << amount << " damage " << std::endl;
		}
		else
		{
			this->_hit_point = 0;
			std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "get " << amount << " damage  [dead!!]" << std::endl;
		}
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_energy_points)
		std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "not enough energy!! (beRepaired Cancel)" << std::endl;
	else if (!this->_hit_point)
		std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "dead!! (beRepaired Cancel)" << std::endl;
	else
	{
		this->_energy_points--;
		this->_hit_point += amount;
		std::cout << std::setw(15) << "[ClapTrap] "  << std::setw(10) << this->_name << "ahaahang~! Kimochi~ " << amount << " repaired" <<std::endl;
	}
}
