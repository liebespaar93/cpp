/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:40 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:40:23 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

class Dog: public AAnimal
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
