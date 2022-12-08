/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:40 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 02:28:25 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
private:
	/* data */
	Brain*	_brain;

public:
	Dog();
	Dog(const Dog& ref);
	~Dog();

	Dog&	operator=(const Dog& ref);
	
	void	makeSound() const;

	Brain*	get_brain( void ) const;
};

#endif
