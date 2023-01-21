/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:49:14 by intra42           #+#    #+#             */
/*   Updated: 2023/01/21 15:02:24 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap():
	ClapTrap("Default_clap_name"),
	ScavTrap("Default_clap_name"),
	FragTrap("Default_clap_name"),
	_name("Default")
{
	this->_hit_point = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
	std::cout << std::setw(15) << "[DiamondTrap] " << std::setw(10) << this->_name << "DiamondTrap created!!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"),
	ScavTrap(name + "_clap_name"),
	FragTrap(name + "_clap_name"),
	_name(name)
{
	this->_hit_point = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
	std::cout << std::setw(15) << "[DiamondTrap] " << std::setw(10) << this->_name << "DiamondTrap created!!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& ref):
	ClapTrap(ref._name + "_clap_name"),
	ScavTrap(ref._name + "_clap_name"),
	FragTrap(ref._name + "_clap_name"),
	_name(ref._name)
{
	this->_hit_point = 100;
	this->_energy_points = 50;
	this->_attack_damage = 30;
	std::cout << std::setw(15) << "[DiamondTrap] " << std::setw(10) << this->_name << "DiamondTrap copy!!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << std::setw(15) << "[DiamondTrap] " << std::setw(10) <<this->_name << "DiamondTrap destroy!!" << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& ref)
{
	this->_name = ref._name;
	ClapTrap::_name = _name + "_clap_name";
	this->_hit_point = ref._hit_point;
	this->_energy_points = ref._energy_points;
	this->_attack_damage = ref._attack_damage;

	std::cout << std::setw(15) << "[DiamondTrap] " << std::setw(10) << this->_name << "operator = " << ref._name << std::endl;
	return (*this);
}

void	DiamondTrap::whoAmI()
{
	std::cout << std::setw(15) << "[DiamondTrap] " << std::setw(10) << this->_name << " : I am your father " << ClapTrap::_name << std::endl;
}
