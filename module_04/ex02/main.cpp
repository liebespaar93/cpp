/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:15:30 by intra42           #+#    #+#             */
/*   Updated: 2022/12/07 19:25:30 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>
#include <iomanip>

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
