/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:27:08 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/25 05:05:21 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "Convert.hpp"

Convert::Convert():
	_str("")
{
}

Convert::Convert(std::string str):
	_str(str)
{
}


Convert::Convert(const Convert& ref):
	_str(ref._str)
{
}

Convert::~Convert()
{
}

Convert&	Convert::operator=(const Convert& ref)
{
	this->_str = ref._str;
	return (*this);
}

bool	ft_isfinite(double	num)
{
	return (num != 0 && num * 2 == num);
}

bool	ft_isnan(double	num)
{
	return (num != num);
}

const std::string Convert::to_char()
{
	double		num;
	std::string	result;

	num = atof(_str.c_str());
	if (ft_isfinite(num) || ft_isnan(num) || (num - static_cast<int>(num)))
		return ("impossible");
	
	if (_str.length() == 1 && std::isprint(_str[0]) && !std::isdigit(_str[0]))
		return ("'" + _str + "'");
	if (num < 256 && std::isprint(num))
	{
		result = static_cast<int>(num);
		return ("'" + result + "'");
	}
	return ("Non displayable");
}

const std::string	Convert::to_int()
{
	double				num;
	std::ostringstream	result;

	num = atof(_str.c_str());
	if (ft_isfinite(num) || ft_isnan(num))
		return ("impossible");
	if (this->_str.length() == 1 && !std::isdigit(_str[0]))
	{
		result << static_cast<int>(_str[0]);
		return (result.str());
	}
	result << atoi(_str.c_str());
	return (result.str());
}

const std::string	Convert::to_float()
{
	float				num;
	std::ostringstream	result;

	num = atof(_str.c_str());
	if (ft_isfinite(num) || ft_isnan(num))
	{
		result << num;
		return (result.str());
	}
	if (this->_str.length() == 1 && !std::isdigit(_str[0]))
	{
		result << static_cast<int>(_str[0]) << ".0f";
		return (result.str());
	}
	result << num;
	if (!strchr(result.str().c_str(), '.'))
	{
		result << ".0f";
		return (result.str());
	}
	result << "f";
	return (result.str());
}

const std::string	Convert::to_double()
{
	double				num;
	std::ostringstream	result;

	num = atof(_str.c_str());
	if (ft_isfinite(num) || ft_isnan(num))
	{
		result << num;
		return (result.str());
	}
	if (this->_str.length() == 1 && !std::isdigit(_str[0]))
	{
		result << static_cast<int>(_str[0]) << ".0";
		return (result.str());
	}
	result << num;
	if (!strchr(result.str().c_str(), '.'))
	{
		result << ".0";
		return (result.str());
	}
	return (result.str());
	
}

void	Convert::convert(const std::string str)
{	
	this->_str = str;
	
	std::cout << "char: " << to_char() << std::endl;
	std::cout <<  "int: " << to_int() << std::endl;
	std::cout <<  "float: " << to_float() << std::endl;
	std::cout <<  "double: " << to_double() << std::endl;
}
