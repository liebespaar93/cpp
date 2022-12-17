/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:35 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:38:57 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "WrongCat.hpp"

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
