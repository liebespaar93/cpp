/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:33 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 02:28:19 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <string>

class WrongAnimal
{
protected:
	/* data */
	std::string _type;

public:
	WrongAnimal();
	WrongAnimal(std::string type);
	WrongAnimal(const WrongAnimal& ref);
	virtual	~WrongAnimal();

	WrongAnimal&	operator=(const WrongAnimal& ref);

	const std::string&	getType() const;
	
	void makeSound() const;
};

#endif
