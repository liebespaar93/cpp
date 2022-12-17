/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:40 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 07:02:59 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
private:
	/* data */

public:
	Dog();
	Dog(const Dog& ref);
	~Dog();

	Dog&	operator=(const Dog& ref);
	
	void	makeSound() const;

};

#endif
