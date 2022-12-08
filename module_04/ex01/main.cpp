/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 18:15:30 by intra42           #+#    #+#             */
/*   Updated: 2022/12/07 19:08:42 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"

#include <iostream>
#include <iomanip>

int main( void )
{
    std::cout << std::setfill(' ') << std::left;
	
	const Animal* dog = new Dog();
	const Animal* cat = new Cat();

	std::cout << std::endl;

	delete dog;
	delete cat;
	system("leaks a.out");
	std::cout << std::endl;
	std::cout << std::endl;

	// Proof of deep copy
	Dog medor;
	Cat fifi;

	fifi.get_brain()->set_ideas("test5", 1);
	Dog & medor_ref = medor;
	Cat & fifi_ref = fifi;

	std::cout << std::endl << "creating copies" << std::endl;
	Dog medor_copy(medor_ref);
	Cat fifi_copy(fifi_ref);

	Dog medor_copy_ref = medor_copy;
	Cat fifi_copy_ref = fifi_copy;
	std::cout << std::endl << "comparing" << std::endl;
	std::cout << std::setw(15) << "medor" << "brain's heap address: " << static_cast<void*>(medor.get_brain()) << std::endl;
	std::cout << std::setw(15) << "medor_ref" << "brain's heap address: " << static_cast<void*>(medor_ref.get_brain()) << std::endl;
	std::cout << std::setw(15) << "medor_copy" << "brain's heap address: " << static_cast<void*>(medor_copy.get_brain()) << std::endl;
	std::cout << std::setw(15) << "medor_copy_ref" << "brain's heap address: " << static_cast<void*>(medor_copy_ref.get_brain()) << std::endl;

	std::cout << std::setw(15) << "fifi" << "brain's heap address: " << static_cast<void*>(fifi.get_brain()) << std::endl;
	std::cout << std::setw(15) << "fifi_ref" << "brain's heap address: " << static_cast<void*>(fifi_ref.get_brain()) << std::endl;
	std::cout << std::setw(15) << "fifi_copy" << "brain's heap address: " << static_cast<void*>(fifi_copy.get_brain()) << std::endl;
	std::cout << std::setw(15) << "fifi_copy_ref" << "brain's heap address: " << static_cast<void*>(fifi_copy_ref.get_brain()) << std::endl;

	medor.get_brain()->set_ideas("test1", 1);
	medor_ref.get_brain()->set_ideas("test2", 1);
	medor_copy.get_brain()->set_ideas("test3", 1);
	medor_copy_ref.get_brain()->set_ideas("test4", 1);

	std::cout << std::setw(15) << "medor" << "brain's array[0]: " << medor.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "medor_ref" << "brain's array[0]: " << medor_ref.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "medor_copy" << "brain's array[0]: " << medor_copy.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "medor_copy_ref" << "brain's array[0]: " << medor_copy_ref.get_brain()->get_ideas()[0] << std::endl;

	std::cout << std::endl;

	std::cout << std::setw(15) << "fifi" << "brain's array[0]: " << fifi.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "fifi_ref" << "brain's array[0]: " << fifi_ref.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "fifi_copy" << "brain's array[0]: " << fifi_copy.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "fifi_copy_ref" << "brain's array[0]: " << fifi_copy_ref.get_brain()->get_ideas()[0] << std::endl;
	
	fifi_ref.get_brain()->set_ideas("test6", 1);
	fifi_copy_ref.get_brain()->set_ideas("test7", 1);
	
	std::cout << std::endl;

	std::cout << std::setw(15) << "fifi" << "brain's array[0]: " << fifi.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "fifi_ref" << "brain's array[0]: " << fifi_ref.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "fifi_copy" << "brain's array[0]: " << fifi_copy.get_brain()->get_ideas()[0] << std::endl;
	std::cout << std::setw(15) << "fifi_copy_ref" << "brain's array[0]: " << fifi_copy_ref.get_brain()->get_ideas()[0] << std::endl;
	
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
