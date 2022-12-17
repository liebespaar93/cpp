/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:02:50 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 14:12:25 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "HumanA.hpp"

HumanA::~HumanA() {}

HumanA::HumanA(std::string name, Weapon &weapon)
	: _name(name), _weapon(weapon) {}

void HumanA::attack()
{
	if (!this->_weapon.getType().empty())
		std::cout << this->_name << " attacks with their " << this->_weapon.getType() << std::endl;
	else
		std::cout << this->_name << " attacks with their hand" << std::endl;
}
