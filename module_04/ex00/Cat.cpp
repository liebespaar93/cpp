/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:35 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 07:04:19 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Cat.hpp"

Cat::Cat():
	Animal("cat")
{
	std::cout << std::setw(15) << "[Cat] " << "Cat come!!" << std::endl;
}

Cat::Cat(const Cat& ref):
	Animal(ref._type)
{
	std::cout << std::setw(15) << "[Cat] " << "Cat come!! (copy)" << std::endl;
}

Cat::~Cat()
{
	std::cout << std::setw(15) << "[Cat] " << "Cat leave!!" << std::endl;
}

Cat&	Cat::operator=(const Cat& ref)
{
	this->_type = ref._type;
	std::cout << std::setw(15) << "[Cat] " << "Cat operator" << std::endl;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << std::setw(15) << "[Cat] " << "😺 : Meow~! Hiss~!" << std::endl;
}
