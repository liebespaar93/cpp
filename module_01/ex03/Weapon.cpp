/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:21:28 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/02 11:42:10 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Weapon.hpp>
#include <iostream>

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
