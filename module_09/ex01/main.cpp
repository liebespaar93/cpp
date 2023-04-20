/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 04:50:07 by kyoulee           #+#    #+#             */
/*   Updated: 2023/04/20 04:50:08 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#include "RPN.hpp"

int main(int argc, char const *argv[])
{
	RPN	*RPN_ptr = NULL;

	if (argc != 2)
	{
		std::cerr << "Error: argc != 2" << '\n';
		return (1);
	}
	try
	{
		/* code */
		RPN_ptr = new RPN(argv[1]);
		std::cout << RPN_ptr->ft_get_result() << std::endl;
	}
	catch(const std::exception& e)
	{
		if (RPN_ptr)
			delete RPN_ptr;
		std::cerr << e.what() << '\n';
		return (1);
	}
	delete RPN_ptr;

    return 0;
}
