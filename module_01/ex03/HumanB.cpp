/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:02:52 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 14:12:46 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

#include "HumanB.hpp"

HumanB::~HumanB() {}

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {}

void HumanB::setWeapon(Weapon &weapon)
{
	this->_weapon = &weapon;
}

void HumanB::attack()
{
	if (_weapon)
		std::cout << this->_name << " attacks with their " << this->_weapon->getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their hand" << std::endl;
}
