/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:51:03 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/06 01:50:46 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

#include <iomanip>

ClapTrap::ClapTrap():
	_name("Default"),
	_hit_point(10),
	_energy_points(10),
	_attack_damage(0) 
{
	std::cout << "[ClapTrap] "  << std::setw(10) << this->_name << "ClapTrap created!!" << std::endl;
}

ClapTrap::ClapTrap(std::string name):
	_name(name),
	_hit_point(10),
	_energy_points(10),
	_attack_damage(0) 
{
	std::cout << "[ClapTrap] "  << std::setw(10) << this->_name << "ClapTrap created!!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ref):
	_name(ref._name),
	_hit_point(ref._hit_point),
	_energy_points(ref._energy_points),
	_attack_damage(ref._attack_damage) 
{
	std::cout << "[ClapTrap] "  << std::setw(10) << this->_name << "ClapTrap created!!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "[ClapTrap] "  << std::setw(10) <<this->_name << "ClapTrap destroy!!" << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& ref)
{
	this->_name = ref._name;
	this->_hit_point = ref._hit_point;
	this->_energy_points = ref._energy_points;
	this->_attack_damage = ref._attack_damage;

	std::cout << "[ClapTrap] "  << std::setw(10) << this->_name << "operator = " << ref._name << std::endl;
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!this->_energy_points)
		std::cout << "[ClapTrap] "  << std::setw(10) << this->_name << "not enough energy!! (Attack Cancel)" << std::endl;
	else
		std::cout << "[ClapTrap] "  << std::setw(10) << this->_name << "Attack !! " << target << " hit " << this->_attack_damage << " damage"<< std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_energy_points < amount)
	{
		this->_energy_points = 0;
		std::cout << "[ClapTrap] "  << std::setw(10) << this->_name << "fucking hurt!! " << amount << " damage !! empty energy" << std::endl;
	}
	else
	{
		this->_energy_points -= amount;
		std::cout << "[ClapTrap] "  << std::setw(10) << this->_name << "get " << amount << " damage " << std::endl;
	}
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!this->_energy_points)
		std::cout << "[ClapTrap] "  << std::setw(10) << this->_name << "not enough energy!! (Repair Cancel)" << std::endl;
	else
	{
		this->_energy_points += amount;
		std::cout << "[ClapTrap] "  << std::setw(10) << this->_name << "ahaahang~! Kimochi~ " << amount << " repaired" <<std::endl;
	}
}
