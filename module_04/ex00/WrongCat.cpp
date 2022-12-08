/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:35 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 02:28:21 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

#include <iostream>
#include <iomanip>

WrongCat::WrongCat():
	WrongAnimal("cat")
{
	std::cout << std::setw(15) << "[WrongCat] " << "Cat come!!" << std::endl;
}

WrongCat::WrongCat(const WrongCat& ref):
	WrongAnimal(ref._type)
{
	std::cout << std::setw(15) << "[WrongCat] " << "Cat come!! (copy)" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << std::setw(15) << "[WrongCat] " << "Cat leave!!" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& ref)
{
	this->_type = ref._type;
	std::cout << std::setw(15) << "[WrongCat] " << "Cat operator" << std::endl;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << std::setw(15) << "[WrongCat] " << "😺 : Meow~! Hiss~!" << std::endl;
}
