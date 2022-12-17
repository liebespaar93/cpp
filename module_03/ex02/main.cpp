/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:51:05 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 21:10:12 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
    std::cout << std::setfill(' ') << std::left;

	ScavTrap *c1 = new ScavTrap();
	FragTrap *c2 = new FragTrap("Zoro");
	FragTrap *aux = new FragTrap("shaco");
	FragTrap *c3 = new FragTrap(*aux);

	std::cout << std::endl;

	c1->attack("Slime");
	c2->attack("Sanji");
	c3->attack("Slime shiny");

	std::cout << std::endl;

	c1->takeDamage(20);
	c2->takeDamage(50);
	c2->takeDamage(50);
	c3->takeDamage(5);

	std::cout << std::endl;

	c1->beRepaired(1000);
	c2->beRepaired(1);
	c3->beRepaired(5);

	std::cout << std::endl;

	c1->guardGate();

	std::cout << std::endl;
	
	c2->highFivesGuys();
	c3->highFivesGuys();

	std::cout << std::endl;

	delete c1;
	delete c2;
	delete aux;
	delete c3;
}
