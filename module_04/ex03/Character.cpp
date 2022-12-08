/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:23:58 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 19:42:34 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Character.hpp"

Character::Character():
	_name("Defualt"),
	_idx(0)
{
	for (int i = 0; i < this->_max_inventory ; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const std::string& name):
	_name(name),
	_idx(0)
{
	for (int i = 0; i < this->_max_inventory ; i++)
		this->_inventory[i] = NULL;
}

Character::Character(const Character& ref)
{
	this->_name = ref._name;
	this->_idx = ref._idx;
	for (int i = 0; i < this->_max_inventory ; i++)
		this->_inventory[i] = ref._inventory[i];
}

Character::~Character() { }

Character&	Character::operator=(const Character& ref)	
{
	this->_name = ref._name;
	this->_idx = ref._idx;
	for (int i = 0; i < this->_max_inventory ; i++)
		this->_inventory[i] = ref._inventory[i]->clone();
	return (*this);
}

std::string const & Character::getName() const
{
	return (this->_name);
}

void	Character::equip(AMateria* m)
{
	if (this->_idx < this->_max_inventory)
		this->_inventory[this->_idx++] = m;
	else
		std::cout << "no more inventory!!" << std::endl;
		
}

void	Character::unequip(int idx)
{
	if (this->_idx >= 0)
	{
		if (this->_inventory[idx])
		{
			this->_inventory[idx] = NULL;
			this->_idx--;
		}
		for (int i = idx; i < this->_max_inventory - 1; i++)
			this->_inventory[i] = this->_inventory[i + 1];
		this->_inventory[this->_max_inventory - 1] = NULL;
	}
	else
		std::cout << "no more inventory!!" << std::endl;
}

void	Character::use(int idx, ICharacter& target)
{
	if (0 <= idx && idx < this->_max_inventory && this->_inventory[idx])
		this->_inventory[idx]->use(target);
	else 
		std::cout << "inventory["<< idx << "] is empty" << std::endl;
}
