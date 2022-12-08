/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:31 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 02:28:22 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

#include <iostream>
#include <iomanip>

Animal::Animal():
	_type("Default")
{
	std::cout << std::setw(15) << "[Animal] " << this->_type << " Animal come!!" << std::endl;
}

Animal::Animal(std::string type):
	_type(type)
{
	std::cout << std::setw(15) << "[Animal] " << this->_type << " Animal come!!" << std::endl;
}

Animal::Animal(const Animal& ref):
	_type(ref._type)
{
	std::cout << std::setw(15) << "[Animal] " << this->_type << " Animal come!! (copy)" << std::endl;
}

Animal::~Animal()
{
	std::cout << std::setw(15) << "[Animal] " << this->_type << " Animal leave!!" << std::endl;
}

Animal& Animal::operator=(const Animal& ref)
{
	this->_type = ref._type;
	std::cout << std::setw(15) << "[Animal] " << this->_type << "Animal operator" << std::endl;
	return (*this);
}

void	Animal::makeSound() const
{
	std::cout << std::setw(15) << "[Animal] "<< this->_type << "some Animal sound" << std::endl;
}

const std::string& Animal::getType() const
{
	return (this->_type);
}
