/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:51:05 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/21 14:04:04 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iomanip>
#include <iostream>

#include "ClapTrap.hpp"

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    std::cout << std::setfill(' ') << std::left;
    
	ClapTrap *c1 = new ClapTrap("A");
	ClapTrap *c2 = new ClapTrap("B");
	ClapTrap *c3 = new ClapTrap(*c1);
	ClapTrap *c4 = new ClapTrap("E");
	ClapTrap oper;

	oper.attack("");
	oper = *c1;
	oper.attack("");

	std::cout << std::endl;

	for (int i = 1; i <= 12 ;  i++)
	{
		std::cout << "[" << std::setw(2) << i << "]";
		c4->attack("");
	}
	c4->takeDamage(5);
	c4->beRepaired(5);
	
	
	std::cout << std::endl;

	c1->attack("F");
	c2->attack("G");
	c3->attack("H");
	std::cout << std::endl;

	c1->takeDamage(80);
	c2->takeDamage(5);
	c2->takeDamage(5);
	c2->takeDamage(5);
	c3->takeDamage(5);

	std::cout << std::endl;

	c1->beRepaired(1000);
	c2->beRepaired(1);
	c3->beRepaired(5);

	std::cout << std::endl;

	delete c1;
	delete c2;
	delete c3;
	delete c4;
    return 0;
}
