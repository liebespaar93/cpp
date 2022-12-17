/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:31 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 07:05:25 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "WrongAnimal.hpp"

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
