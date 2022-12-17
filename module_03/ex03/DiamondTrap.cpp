/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 00:49:14 by intra42           #+#    #+#             */
/*   Updated: 2022/12/17 21:11:11 by kyoulee          ###   ########.fr       */
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
	ScavTrap(),
	FragTrap(),
	_name("Default")
{
	ClapTrap::_name = _name + "_clap_name";
	this->_hit_point = FragTrap::_hit_point;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << std::setw(15) << "[DiamondTrap] " << std::setw(10) << this->_name << "DiamondTrap created!!" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name"),
	ScavTrap(name),
	FragTrap(name),
	_name(name)
{
	ClapTrap::_name = _name + "_clap_name";
	this->_hit_point = FragTrap::_hit_point;
	this->_energy_points = ScavTrap::_energy_points;
	this->_attack_damage = FragTrap::_attack_damage;
	std::cout << std::setw(15) << "[DiamondTrap] " << std::setw(10) << this->_name << "DiamondTrap created!!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& ref):
	ClapTrap(ref._name + "_clap_name"),
	ScavTrap(ref._name),
	FragTrap(ref._name),
	_name(ref._name)
{
	ClapTrap::_name = _name + "_clap_name";
	this->_hit_point = ref._hit_point;
	this->_energy_points = ref._energy_points;
	this->_attack_damage = ref._attack_damage;
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
	std::cout << std::setw(15) << "[DiamondTrap] " << std::setw(10) << this->_name << " : I am your father" << std::endl;
}
