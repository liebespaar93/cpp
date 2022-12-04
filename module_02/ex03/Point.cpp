/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 14:46:48 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/05 05:57:02 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Point.hpp"

Point::Point() {}

Point::~Point() {}


Point::Point(const float x, const float y) :
	_x(x), _y(y)
{}

Point::Point(Fixed x, Fixed y) :
	_x(x), _y(y)
{}

Point::Point(const Point& ref) :
	_x(ref._x), _y(ref._y)
{}

Point&	Point::operator=(const Point& ref)
{
	this->set_x(ref.get_x().getRawBits());
	this->set_y(ref.get_y().getRawBits());
	return (*this);
}

Fixed	Point::get_x() const { return (this->_x); }
Fixed	Point::get_y() const { return (this->_y); }
void	Point::set_x(float value) { this->get_x().setRawBits(value); }
void	Point::set_y(float value) { this->get_y().setRawBits(value); }

int	Point::get_x_sign() const
{
	int	fractional_bits = this->_x.getRawBits();

	if (fractional_bits & 0x80000000)
		return (1);
	return (0);
}

int	Point::get_y_sign() const
{
	int	fractional_bits = this->_y.getRawBits();

	if (fractional_bits & 0x80000000)
		return (1);
	return (0);
}
