/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:38 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 02:28:27 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Brain.hpp"

#include <iostream>
#include <iomanip>

Dog::Dog():
	AAnimal("dog")
{
	this->_brain = new Brain;
	std::cout << std::setw(15) << "[Dog] " << "Dog come!!" << std::endl;
}

Dog::Dog(const Dog& ref):
	AAnimal(ref._type)
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
