/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:15:30 by intra42           #+#    #+#             */
/*   Updated: 2023/01/25 00:46:08 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

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

	system("leaks a.out");

	Animal* animal = new Animal();
	Animal* dog = new Dog();
	Animal* cat = new Cat();
	Animal oper;

	std::cout << dog->getType() << " " << std::endl;
	std::cout << cat->getType() << " " << std::endl;

	oper = *dog;
	
	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;
	
	std::cout << std::endl;

	std::cout << "========== Wrong ==========" << std::endl;
	
	const WrongAnimal* w_animal= new WrongAnimal();
	const WrongAnimal* w_cat = new WrongCat();

	std::cout << w_cat->getType() << " " << std::endl;
	
	w_animal->makeSound();
	w_cat->makeSound();

	std::cout << std::endl;

	delete w_animal;
	delete w_cat;
	
	std::cout << std::endl;

	system("leaks a.out");
	return 0;
}
