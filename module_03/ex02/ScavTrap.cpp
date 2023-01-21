/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:03:15 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/21 14:08:22 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "ScavTrap.hpp"

ScavTrap::ScavTrap():
	ClapTrap()
{
	this->_hit_point = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << std::setw(15) << "[ScavTrap] " << std::setw(10) << this->_name << "ScavTrap created!! " << std::endl;
}

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name)
{
	this->_hit_point = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << std::setw(15) << "[ScavTrap] " << std::setw(10) << this->_name << "ScavTrap created!! " << std::endl;
}

ScavTrap::ScavTrap(ScavTrap& ref):
	ClapTrap(ref._name)
{
	this->_hit_point = ref._hit_point;
	this->_energy_points = ref._energy_points;
	this->_attack_damage = ref._attack_damage;
	std::cout << std::setw(15) << "[ScavTrap] " << std::setw(10) << this->_name << "ScavTrap copy!! " << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << std::setw(15) << "[ScavTrap] " << std::setw(10) << this->_name << "ScavTrap destory!! " << std::endl;
}

ScavTrap&	ScavTrap::operator=(ScavTrap& ref)
{
	std::string	old_name;

	old_name = this->_name;
	this->_name = ref._name;
	this->_hit_point = ref._hit_point;
	this->_energy_points = ref._energy_points;
	this->_attack_damage = ref._attack_damage;
	std::cout << std::setw(15) << "[ScavTrap] " << std::setw(10) << old_name << "operator = " << ref._name << std::endl;
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (!this->_energy_points)
		std::cout << std::setw(15) << "[ScavTrap] "  << std::setw(10) << this->_name << "not enough energy!! (Attack Cancel)" << std::endl;
	else if (!this->_hit_point)
		std::cout << std::setw(15) << "[ScavTrap] "  << std::setw(10) << this->_name << "dead!! (Attack Cancel)" << std::endl;
	else
	{
		this->_energy_points--;
		std::cout << std::setw(15) << "[ScavTrap] "  << std::setw(10) << this->_name << "Attack !! " << target << " hit " << this->_attack_damage << " damage " << std::endl;
	}
}

void	ScavTrap::guardGate()
{
	if (!this->_energy_points)
		std::cout << std::setw(15) << "[ScavTrap] "  << std::setw(10) << this->_name << "not enough energy!! (guardGate Cancel)" << std::endl;
	else if (!this->_hit_point)
		std::cout << std::setw(15) << "[ScavTrap] "  << std::setw(10) << this->_name << "dead!! (guardGate Cancel)" << std::endl;
	else
	{
		this->_energy_points--;
		std::cout << std::setw(15) << "[ScavTrap] " << std::setw(10) << this->_name << "mot gina ganda~~! " << this->_name << " guardGate " << std::endl;
	}
}
