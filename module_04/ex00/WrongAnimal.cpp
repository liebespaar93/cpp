/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:31 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 02:28:17 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

#include <iostream>
#include <iomanip>

WrongAnimal::WrongAnimal():
	_type("Default")
{
	std::cout << std::setw(15) << "[WrongAnimal] " << this->_type << "Animal come!!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string type):
	_type(type)
{
	std::cout << std::setw(15) << "[WrongAnimal] " << this->_type << "Animal come!!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& ref):
	_type(ref._type)
{
	std::cout << std::setw(15) << "[WrongAnimal] " << this->_type << "Animal come!! (copy)" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << std::setw(15) << "[WrongAnimal] " << this->_type << "Animal leave!!" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& ref)
{
	this->_type = ref._type;
	std::cout << std::setw(15) << "[WrongAnimal] " << this->_type << "Animal operator" << std::endl;
	return (*this);
}

void	WrongAnimal::makeSound() const
{
	std::cout << std::setw(15) << "[WrongAnimal] " << this->_type << "some Animal sound" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return (this->_type);
}
