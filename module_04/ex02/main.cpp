/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:15:30 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:40:41 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main( void )
{
    std::cout << std::setfill(' ') << std::left;

	//const AAnimal* meta = new AAnimal();
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	//meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	std::cout << std::endl;

	//delete meta;
	delete i;
	delete j;
	
	std::cout << std::endl;
}
