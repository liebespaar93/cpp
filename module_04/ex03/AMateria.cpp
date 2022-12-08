/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:38:26 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 19:03:55 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "AMateria.hpp"

AMateria::AMateria():
	_type("Defualt")
{
}

AMateria::AMateria(std::string const & type):
	_type(type)
{
}


AMateria::AMateria(const AMateria& ref)
{
	*this = ref;
}

AMateria::~AMateria()
{
}


AMateria&	AMateria::operator=(const AMateria& ref)
{
	this->_type = ref._type;
	return (*this);
}

std::string const &	AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter& target)
{
	std::cout << "AMateria abstractly used on " << target.getName() << std::endl;
}
