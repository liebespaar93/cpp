/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 04:49:54 by kyoulee           #+#    #+#             */
/*   Updated: 2023/04/20 04:50:10 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string ao_str)
{
	size_t      pos = 0;
	std::string token;

	while (!ao_str.empty())
	{
		if ((pos = ao_str.find(" ")) == std::string::npos)
			pos = ao_str.size();
		token = ao_str.substr(0, pos);
		if (token.length() == 1)
		{
			switch (token.at(0))
			{
			case '+':
				this->ft_caculate_add();
				break;
			case '-':
				this->ft_caculate_min();
				break;
			case '*':
				this->ft_caculate_mul();
				break;
			case '/':
				this->ft_caculate_div();
				break;
			default:
				if (std::isdigit(token.at(0)))
					this->_num_stack.push(atof(token.c_str()));
				else
					throw RPNError("input bad arg");
				break;
			}
		}
		else
			throw RPNError("input bad arg");
		ao_str.erase(0, pos + 1);
	}
}

RPN::RPN(const RPN& ref)
{
	this->_num_stack = ref._num_stack;
}

RPN::~RPN()
{

}

RPN&	RPN::operator=(const RPN& ref)
{
	this->_num_stack = ref._num_stack;
	return (*this);
}

void	RPN::ft_caculate_add()
{
	double	pop1;
	double	pop2;
	
	if (this->_num_stack.size() < 2)
		throw RPNError("not enough stack");
	pop2 = this->_num_stack.top();
	this->_num_stack.pop();
	pop1 = this->_num_stack.top();
	this->_num_stack.pop();
	this->_num_stack.push(pop1 + pop2);
}

void	RPN::ft_caculate_min()
{
	double	pop1;
	double	pop2;
	
	if (this->_num_stack.size() < 2)
		throw RPNError("not enough stack");
	pop2 = this->_num_stack.top();
	this->_num_stack.pop();
	pop1 = this->_num_stack.top();
	this->_num_stack.pop();
	this->_num_stack.push(pop1 - pop2);
}

void	RPN::ft_caculate_mul()
{
	double	pop1;
	double	pop2;
	
	if (this->_num_stack.size() < 2)
		throw RPNError("not enough stack");
	pop2 = this->_num_stack.top();
	this->_num_stack.pop();
	pop1 = this->_num_stack.top();
	this->_num_stack.pop();
	this->_num_stack.push(pop1 * pop2);
}
void	RPN::ft_caculate_div()
{
	double	pop1;
	double	pop2;
	
	if (this->_num_stack.size() < 2)
		throw RPNError("not enough stack");
	pop2 = this->_num_stack.top();
	this->_num_stack.pop();
	pop1 = this->_num_stack.top();
	this->_num_stack.pop();
	this->_num_stack.push(pop1 / pop2);
}

std::string	RPN::ft_get_result()
{
	std::ostringstream result;

	result << this->_num_stack.top();
	if (this->_num_stack.size() != 1)
		throw RPNError();
	return (result.str());
}

RPN::RPNError::RPNError()
	: _message("Error")
{

}

RPN::RPNError::RPNError(std::string errormessege)
	: _message("Error: " + errormessege)
{

}

const char* RPN::RPNError::what() const throw()
{
	return (this->_message.c_str());
}



