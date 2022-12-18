/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 08:26:31 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/18 09:59:14 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#include "Convert.hpp"

int main(int argc, char const *argv[])
{
	Convert	convert;

	if (argc == 1)
	{
		std::cout << "Error : ex) convert <str>" << std::endl;
		return (1);
	}
	convert.convert(argv[1]);
	return (0);
}
