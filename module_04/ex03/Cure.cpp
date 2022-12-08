/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:19 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 19:15:05 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Cure.hpp"

Cure::Cure():
	AMateria("cure")
{
}

Cure::Cure(const Cure& ref):
	AMateria("cure")
{
	this->_type = ref._type;
}

Cure::~Cure()
{
}

Cure&	Cure::operator=(const Cure& ref)
{
	this->_type = ref._type;
	std::cout << std::setw(15) << "[Cure] " << "operator=!!" << std::endl;
	return (*this);
}

AMateria*	Cure::clone() const
{
	return (new Cure(*this));
}


void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
