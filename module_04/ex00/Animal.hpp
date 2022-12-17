/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:33 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:38:07 by kyoulee          ###   ########.fr       */
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
