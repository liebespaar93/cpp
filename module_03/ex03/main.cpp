/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:51:05 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 21:13:53 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"


int main()
{
    std::cout << std::setfill(' ') << std::left;
	
	ScavTrap *c1 = new ScavTrap();
	std::cout << std::endl;
	FragTrap *c2 = new FragTrap("shacho");
	std::cout << std::endl;
	DiamondTrap *c3 = new DiamondTrap("Zoro");
	std::cout << std::endl;
	DiamondTrap *c4 = new DiamondTrap();
	std::cout << std::endl;
	DiamondTrap *aux = new DiamondTrap(*c3);

	std::cout << std::endl;
	DiamondTrap oper("oper");
	oper = *c3;
	
	std::cout << std::endl;

	c1->attack("Slime");
	c2->attack("Sanji");
	c3->attack("Slime shiny");

	std::cout << std::endl;

	c1->takeDamage(80);
	c2->takeDamage(50);
	c2->takeDamage(50);
	c3->takeDamage(5);

	std::cout << std::endl;

	c1->beRepaired(1000);
	c2->beRepaired(1);
	c3->beRepaired(5);
	c4->beRepaired(5);
	
	std::cout << std::endl;

	c1->guardGate();
	c3->guardGate();

	std::cout << std::endl;

	c2->highFivesGuys();
	c3->highFivesGuys();

	c3->whoAmI();
	c4->whoAmI();

	std::cout << std::endl;

	delete c1;
	delete c2;
	delete c3;
	delete c4;
	delete aux;
}
