/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:15:30 by intra42           #+#    #+#             */
/*   Updated: 2023/01/25 00:52:59 by kyoulee          ###   ########.fr       */
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

	//const AAnimal* aanimal = new AAnimal();
	const AAnimal* dog = new Dog();
	const AAnimal* cat = new Cat();

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;
	
	//aanimal->makeSound();
	dog->makeSound(); //will output the cat sound!
	cat->makeSound();

	std::cout << std::endl;

	//delete aanimal;
	delete dog;
	delete cat;
	
	std::cout << std::endl;
}
