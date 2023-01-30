/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:16:35 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/30 14:19:29 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Data.hpp"

Data::Data():
	ptr(0)
{
	std::cout << std::setw(15) << "[Data] " << "create!!" << std::endl;
}

Data::Data(const Data& ref):
	ptr(ref.ptr)
{
	*this=ref;
	std::cout << std::setw(15) << "[Data] " << "copy!!" << std::endl;
}

Data::~Data()
{
	std::cout << std::setw(15) << "[Data] " << "delete!!" << std::endl;
}

Data&	Data::operator=(const Data& ref)
{
	this->ptr=ref.ptr;
	std::cout << std::setw(15) << "[Data] " << "operator=!!" << std::endl;
	return (*this);
}
