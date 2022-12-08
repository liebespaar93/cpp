/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:15:30 by intra42           #+#    #+#             */
/*   Updated: 2022/12/06 18:50:55 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

#include <iostream>
#include <iomanip>

int main()
{
    std::cout << std::setfill(' ') << std::left;

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	std::cout << std::endl;

	delete meta;
	delete i;
	delete j;
	
	std::cout << std::endl;

	std::cout << "========== Wrong ==========" << std::endl;
	
	const WrongAnimal* w_meta = new WrongAnimal();
	const WrongAnimal* w_i = new WrongCat();
	std::cout << w_i->getType() << " " << std::endl;
	w_i->makeSound(); //will output the cat sound!
	w_meta->makeSound();

	std::cout << std::endl;

	delete w_meta;
	delete w_i;
	
	std::cout << std::endl;

	return 0;
}
