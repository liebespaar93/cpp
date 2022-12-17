/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:26:28 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:38:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Brain.hpp"

Brain::Brain()
{
	std::cout << std::setw(15) << "[Brain] " << "create!! " << std::endl;
}

Brain::Brain(Brain& ref)
{
	for (int i = 0; i < 100 ; i++)
		this->_ideas[i] = ref._ideas[i];
	std::cout << std::setw(15) << "[Brain] " << "copy!! " << std::endl;
}

Brain::~Brain()
{
	std::cout << std::setw(15) << "[Brain] " << "destroy!! " << std::endl;
}

Brain&	Brain::operator=(Brain& ref)
{
	std::cout << std::setw(15) << "[Brain] " << "deep!! " << std::endl;
	for (int i = 0; i < 100 ; i++)
		this->_ideas[i] = ref._ideas[i];
	return (*this);
}

std::string	*Brain::get_ideas()
{
	return (this->_ideas);
}

void	Brain::set_ideas(const std::string& ideas, int index)
{
	if (0 < index && index <= 100)
		this->_ideas[index - 1] = ideas;
	else
		std::cout << "out of index" << std::endl;
}
