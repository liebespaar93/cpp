/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:31 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:38:44 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Animal.hpp"

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
