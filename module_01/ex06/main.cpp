/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:07:31 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 14:47:28 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Harl.hpp"


int	main(int argc, char *argv[])
{
	Harl	harl;

	if (argc != 2)
	{
		std::cout << "just two argment in tester" << std::endl;
		return (1);
	}
	harl.complain(argv[1]);
	return (0);
}
