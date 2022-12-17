/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:21:28 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 14:13:26 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {
	this->_type.clear();
}

Weapon::Weapon(std::string type)
{
	this->_type = type;
}

Weapon::~Weapon() {}

std::string	&Weapon::getType()
{
	return (this->_type); 
}

void	Weapon::setType(std::string type)
{
	this->_type = type;
}
