/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:19:46 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/05 02:11:38 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

#include <iostream>

Fixed::Fixed() :
	_fractional_bits(0) 
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed &ref)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = ref;
}

Fixed&	Fixed::operator=(const Fixed &ref)
{
	std::cout << "Copy assignment operator called" << std::endl;
	setRawBits(ref.getRawBits());
	return (*this);
}

int	Fixed::getRawBits() const
{
	// std::cout << "getRawBits member function called" << std::endl;
	return (this->_fractional_bits);
}

void Fixed::setRawBits(const int &value)
{
	this->_fractional_bits = value;
}

//=============================== ex00 ===============================//

Fixed::Fixed(const int &value)
{
	t_float_point_fractional_bits	fractional_point;
	t_float_point					temp;

	std::cout << "Int constructor called" << std::endl;
	
	fractional_point.fractional_bits = 0;
	temp.int_point = value;
	if (temp.s_bit.sign)
	{
		fractional_point.s_bit.sign = 1;
		temp.int_point *= -1;
	}
	fractional_point.s_bit.expt = temp.int_point;
	this->_fractional_bits = fractional_point.fractional_bits;
}

Fixed::Fixed(const float &value)
{
	t_float_point_fractional_bits	fractional_point;
	t_float_point					temp;

	std::cout << "Float constructor called" << std::endl;

	fractional_point.fractional_bits = 0;
	temp.float_point = value;
	if ((temp.int_point & 0x7fc00000u) == 0x7fc00000u)
		fractional_point.fractional_bits = 0x7fffff80u;
	else if ((temp.int_point & 0xff800000u) == 0xff800000u)
		fractional_point.fractional_bits = 0xffffff00u;
	else if ((temp.int_point & 0x7f800000u) == 0x7f800000u)
		fractional_point.fractional_bits = 0x7fffff00u;
	else
	{
		fractional_point.s_bit.sign = temp.s_bit.sign;
		temp.s_bit.sign = 0;
		fractional_point.s_bit.expt = (long int)temp.float_point;
		temp.float_point = temp.float_point - (long int)temp.float_point + 1;
		fractional_point.s_bit.frac |= temp.s_bit.frac >> (31 - _fractional_bits_len * 2);
		fractional_point.s_bit.frac += (temp.s_bit.frac >> (31 - _fractional_bits_len * 2 - 1)) % 2;
	}
	this->_fractional_bits = fractional_point.fractional_bits;
}

float	Fixed::toFloat( void ) const
{
	t_float_point_fractional_bits	float_point;
	t_float_point					temp;

	float_point.fractional_bits = this->_fractional_bits;
	if (float_point.fractional_bits == 0x7fffff80u)
		return (FIXED_NAN);
	else if (float_point.fractional_bits == 0xffffff00u)
		return (-FIXED_INFINITY);
	else if (float_point.fractional_bits == 0x7fffff00u)
		return (FIXED_INFINITY);
	else
	{
		temp.float_point = 1;
		temp.s_bit.frac |= float_point.s_bit.frac << (31 - _fractional_bits_len * 2);
		temp.float_point += float_point.s_bit.expt - 1;
		temp.s_bit.sign = float_point.s_bit.sign;
	}
	return (temp.float_point);
}

int		Fixed::toInt( void ) const
{
	t_float_point_fractional_bits	float_point;
	
	float_point.fractional_bits = this->_fractional_bits;
	if (float_point.fractional_bits == 0x7fffffff)
		return (0);
	else if (float_point.fractional_bits == 0xffffffff)
		return (-0);
	else if (float_point.s_bit.sign)
		return (float_point.s_bit.expt * -1);
	return (float_point.s_bit.expt);
}

std::ostream &operator<<(std::ostream &os, const Fixed& ref)
{
	os << ref.toFloat();
	return (os);
}
