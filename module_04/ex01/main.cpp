/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:15:30 by intra42           #+#    #+#             */
/*   Updated: 2023/01/25 00:45:01 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

int main( void )
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j; //should not create a leak 
	delete i;

	system("leaks a.out");
	
    std::cout << std::setfill(' ') << std::left;
	
	Dog*	dog = new Dog();
	Cat*	cat = new Cat();
	Dog		oper_dog;
	Cat		oper_cat;

	std::cout << std::endl;


	oper_dog = *dog;
	oper_cat = *cat;
	delete dog;
	delete cat;

	system("leaks a.out");
	std::cout << std::endl;
	std::cout << std::endl;

	
	// Proof of deep copy
	Dog dog_2;
	Cat cat_2;

	cat_2.get_brain()->set_ideas("test5", 1);
	Dog & dog_2_ref = dog_2;
	Cat & cat_2_ref = cat_2;

	std::cout << std::endl << "creating copies" << std::endl;
	Dog dog_2_copy(dog_2_ref);
	Cat cat_2_copy(cat_2_ref);

	Dog dog_2_copy_ref = dog_2_copy;
	Cat cat_2_copy_ref = cat_2_copy;
	std::cout << std::endl << "comparing" << std::endl;
	std::cout << std::setw(15) << "dog_2" << "brain's heap address: " << static_cast<void*>(dog_2.get_brain()) << std::endl;
	std::cout << std::setw(15) << "dog_2_ref" << "brain's heap address: " << static_cast<void*>(dog_2_ref.get_brain()) << std::endl;
	std::cout << std::setw(15) << "dog_2_copy" << "brain's heap address: " << static_cast<void*>(dog_2_copy.get_brain()) << std::endl;
	std::cout << std::setw(15) << "dog_2_copy_ref" << "brain's heap address: " << static_cast<void*>(dog_2_copy_ref.get_brain()) << std::endl;

	std::cout << std::setw(15) << "cat_2" << "brain's heap address: " << static_cast<void*>(cat_2.get_brain()) << std::endl;
	std::cout << std::setw(15) << "cat_2_ref" << "brain's heap address: " << static_cast<void*>(cat_2_ref.get_brain()) << std::endl;
	std::cout << std::setw(15) << "cat_2_copy" << "brain's heap address: " << static_cast<void*>(cat_2_copy.get_brain()) << std::endl;
	std::cout << std::setw(15) << "cat_2_copy_ref" << "brain's heap address: " << static_cast<void*>(cat_2_copy_ref.get_brain()) << std::endl;

	dog_2.get_brain()->set_ideas("test1", 1);
	dog_2_ref.get_brain()->set_ideas("test2", 1);
	dog_2_copy.get_brain()->set_ideas("test3", 1);
	dog_2_copy_ref.get_brain()->set_ideas("test4", 1);

	std::cout << std::setw(15) << "dog_2" << "brain's array[0]: " << dog_2.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "dog_2_ref" << "brain's array[0]: " << dog_2_ref.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "dog_2_copy" << "brain's array[0]: " << dog_2_copy.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "dog_2_copy_ref" << "brain's array[0]: " << dog_2_copy_ref.get_brain()->get_ideas()[0] << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(15) << "cat_2" << "brain's array[0]: " << cat_2.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "cat_2_ref" << "brain's array[0]: " << cat_2_ref.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "cat_2_copy" << "brain's array[0]: " << cat_2_copy.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "cat_2_copy_ref" << "brain's array[0]: " << cat_2_copy_ref.get_brain()->get_ideas()[0] << std::endl;
	
	cat_2_ref.get_brain()->set_ideas("test6", 1);
	cat_2_copy_ref.get_brain()->set_ideas("test7", 1);
	
	std::cout << std::endl;

	std::cout << std::setw(15) << "cat_2" << "brain's array[0]: " << cat_2.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "cat_2_ref" << "brain's array[0]: " << cat_2_ref.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "cat_2_copy" << "brain's array[0]: " << cat_2_copy.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "cat_2_copy_ref" << "brain's array[0]: " << cat_2_copy_ref.get_brain()->get_ideas()[0] << std::endl;
	
	std::cout << std::endl;

	// Array of animals
	const Animal	*(animal_array[4]);
	std::cout << std::endl;
	// Half filled with dogs
	for (int i = 0; i < 2; i++)
		animal_array[i] = new Dog();
	std::cout << std::endl;

	// Half filled with cats
	for (int i = 2; i < 4; i++)
		animal_array[i] = new Cat();
	std::cout << std::endl;

	for (int i = 0; i < 4; i++)
		delete animal_array[i];
	std::cout << std::endl;

	system("leaks a.out");
}
