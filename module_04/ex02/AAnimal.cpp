/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:31 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:38:37 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "AAnimal.hpp"

AAnimal::AAnimal():
	_type("Default")
{
	std::cout << std::setw(15) << "[AAnimal] " << this->_type << " AAnimal come!!" << std::endl;
}

AAnimal::AAnimal(std::string type):
	_type(type)
{
	std::cout << std::setw(15) << "[AAnimal] " << this->_type << " AAnimal come!!" << std::endl;
}

AAnimal::AAnimal(const AAnimal& ref):
	_type(ref._type)
{
	std::cout << std::setw(15) << "[AAnimal] " << this->_type << " AAnimal come!! (copy)" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << std::setw(15) << "[AAnimal] " << this->_type << " AAnimal leave!!" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& ref)
{
	this->_type = ref._type;
	std::cout << std::setw(15) << "[AAnimal] " << this->_type << "AAnimal operator" << std::endl;
	return (*this);
}

void	AAnimal::makeSound() const
{
	std::cout << std::setw(15) << "[AAnimal] "<< this->_type << "some AAnimal sound" << std::endl;
}

const std::string& AAnimal::getType() const
{
	return (this->_type);
}
