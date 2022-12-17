/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:38 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:39:12 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Dog.hpp"
#include "Brain.hpp"

Dog::Dog():
	Animal("dog")
{
	this->_brain = new Brain;
	std::cout << std::setw(15) << "[Dog] " << "Dog come!!" << std::endl;
}

Dog::Dog(const Dog& ref):
	Animal(ref._type)
{
	this->_brain = new Brain(*ref._brain);
	std::cout << std::setw(15) << "[Dog] " << "Dog come!! (copy)" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << std::setw(15) << "[Dog] " << "Dog leave!!" << std::endl;
}

Dog&	Dog::operator=(const Dog& ref)
{
	this->_type = ref._type;
	*this->_brain = *ref._brain;
	std::cout << std::setw(15) << "[Dog] " << "Dog operator" << std::endl;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << std::setw(15) << "[Dog] " << "🐶 : Woof!! Growl~~~" << std::endl;
}

Brain *Dog::get_brain( void ) const
{
	return (this->_brain);
}
