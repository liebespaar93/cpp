/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 06:51:05 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 20:55:16 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << std::setfill(' ') << std::left;
    
	ClapTrap *c1 = new ClapTrap("Clap");
	ScavTrap *c2 = new ScavTrap("Zoro");
	ScavTrap *c3 = new ScavTrap("alpha");
	ScavTrap *aux = new ScavTrap();

    *aux = *c3;
	
	std::cout << std::endl;

	c1->attack("Slime");
	c2->attack("Sanji");
	c3->attack("Slime shiny");

	std::cout << std::endl;

	c1->takeDamage(80);
	c2->takeDamage(5);
	c2->takeDamage(20);
	c3->takeDamage(80);
	aux->takeDamage(20);
	
	ScavTrap c4 = *c2;
	c2->takeDamage(20);
	c2->takeDamage(10);
	
	std::cout << std::endl;

	c1->beRepaired(1000);
	c2->beRepaired(1);
	c3->beRepaired(5);
	aux->beRepaired(100);

	std::cout << std::endl;

	c2->guardGate();
	c3->guardGate();

	std::cout << std::endl;

	delete c1;
	delete c2;
	delete c3;
	delete aux;
}
