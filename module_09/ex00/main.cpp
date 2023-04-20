/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:25:25 by kyoulee           #+#    #+#             */
/*   Updated: 2023/04/20 04:50:05 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// get_time example
#include <iostream>
#include <fstream>

#include <vector>

#include "BitcoinExchange.hpp"

int main(int argc, char const *argv[])
{
	BitcoinExchange		*bit_coin_ptr = NULL;

	if (argc != 2)
	{
		std::cerr << "Error: could not open file." << '\n';
		return (1);
	}

	try 
	{
		bit_coin_ptr = new BitcoinExchange("data.csv", ",");
		bit_coin_ptr->ft_make_exchange(argv[1], "|");
	}
	catch (const std::exception& e)
	{
		if (!bit_coin_ptr)
			delete bit_coin_ptr;
		std::cerr << e.what() << '\n';
		return (2);
	}
	delete bit_coin_ptr;
	return 0;
}
