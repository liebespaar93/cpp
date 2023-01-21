/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:51:05 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/21 14:41:15 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main(int argc, char const *argv[])
{
    (void)argc;
    (void)argv;

    std::cout << std::setfill(' ') << std::left;
    
	DiamondTrap *c1 = new DiamondTrap("A");
	DiamondTrap *c2 = new DiamondTrap("B");
	DiamondTrap *c3 = new DiamondTrap(*c1);
	DiamondTrap *c4 = new DiamondTrap("E");
	DiamondTrap oper;

	oper.attack("");
	oper = *c1;
	oper.attack("");

	std::cout << std::endl;

	for (int i = 1; i <= 52 ;  i++)
	{
		std::cout << "[" << i << "]";
		c4->attack("");
	}
	c4->takeDamage(5);
	c4->beRepaired(5);
	c4->guardGate();
	c4->highFivesGuys();
	c4->whoAmI();
	
	std::cout << std::endl;

	c1->attack("F");
	c2->attack("G");
	c3->attack("H");
	std::cout << std::endl;

	c1->takeDamage(100);
	c2->takeDamage(5);
	c2->takeDamage(5);
	c2->takeDamage(5);
	c3->takeDamage(5);

	std::cout << std::endl;

	c1->beRepaired(1000);
	c2->beRepaired(1);
	c3->beRepaired(5);

	std::cout << std::endl;

	c1->guardGate();
	c2->guardGate();
	c3->guardGate();

	std::cout << std::endl;

	c1->highFivesGuys();
	c2->highFivesGuys();
	c3->highFivesGuys();

	std::cout << std::endl;

	c1->whoAmI();
	c2->whoAmI();
	c3->whoAmI();
	
	std::cout << std::endl;

	delete c1;
	delete c2;
	delete c3;
	delete c4;
    return 0;
}
