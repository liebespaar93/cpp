/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:14:56 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 21:09:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "FragTrap.hpp"

FragTrap::FragTrap():
	ClapTrap()
{
	this->_name = "Default";
	this->_hit_point = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << std::setw(15) << "[FragTrap] " << std::setw(10) << this->_name << "FragTrap created!! " << std::endl;
}

FragTrap::FragTrap(std::string name):
	ClapTrap(name)
{
	this->_name = name;
	this->_hit_point = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << std::setw(15) << "[FragTrap] " << std::setw(10) << this->_name << "FragTrap created!! " << std::endl;
}

FragTrap::FragTrap(FragTrap& ref):
	ClapTrap(ref._name)
{
	this->_name = ref._name;
	this->_hit_point = ref._hit_point;
	this->_energy_points = ref._energy_points;
	this->_attack_damage = ref._attack_damage;
	std::cout << std::setw(15) << "[FragTrap] " << std::setw(10) << this->_name << "FragTrap copy!! " << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << std::setw(15) << "[FragTrap] " << std::setw(10) << this->_name << "FragTrap destory!! " << std::endl;
}

FragTrap&	FragTrap::operator=(FragTrap& ref)
{
	this->_name = ref._name;
	this->_hit_point = ref._hit_point;
	this->_energy_points = ref._energy_points;
	this->_attack_damage = ref._attack_damage;
	std::cout << std::setw(15) << "[FragTrap] " << std::setw(10) << this->_name << "operator = " << ref._name << std::endl;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{

	if (!this->_hit_point)
		std::cout << std::setw(15) << "[FragTrap] " << std::setw(10) << this->_name << "not enough energy!! (highFivesGuys Cancel)" << std::endl;
	else
		std::cout << std::setw(15) << "[FragTrap] " << std::setw(10) << this->_name << "hight fives!!" << std::endl;
}
