/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:38:21 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:59:17 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "MateriaSource.hpp"

MateriaSource::MateriaSource():
	_idx(0)
{
	for (int i = 0; i < this->_max_skill ; i++)
		this->_skill[i] = NULL;
}

MateriaSource::MateriaSource(const MateriaSource& ref):
	_idx(ref._idx)
{
	for (int i = 0; i < this->_max_skill ; i++)
	{
		if (this->_skill[i])
			this->_skill[i] = (ref._skill[i])->clone();
		else
			this->_skill[i] = NULL;
	}
}

MateriaSource::~MateriaSource()
{
	for(int i = 0; i < _max_skill; i++)
	{
		if (this->_skill[i])
			delete this->_skill[i];
	}
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& ref)
{
	this->_idx = ref._idx;
	for(int i = 0; i < _max_skill; i++)
	{
		if (this->_skill[i])
			delete this->_skill[i];
		if (ref._skill[i])
			this->_skill[i] = (ref._skill[i])->clone();
		else
			this->_skill[i] = NULL;
	}
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* ref)
{
	if (this->_idx < this->_max_skill)
		this->_skill[this->_idx++] = ref;
	else
		std::cout << "no more skills" << std::endl;
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	for (int i = 0; i < MateriaSource::_max_skill; i++)
	{
		if (this->_skill[i]->getType() == type)
			return (this->_skill[i]->clone());
	}
	return (NULL);
}
