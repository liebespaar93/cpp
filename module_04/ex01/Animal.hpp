/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:33 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 02:28:23 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <string>

class Animal
{
protected:
	/* data */
	std::string _type;

public:
	Animal();
	Animal(std::string type);
	Animal(const Animal& ref);
	virtual	~Animal();

	Animal&	operator=(const Animal& ref);

	const std::string&	getType() const;
	
	virtual	void makeSound() const;
};

#endif
