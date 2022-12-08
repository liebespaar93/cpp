/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:33 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 02:28:25 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <string>

class AAnimal
{
protected:
	/* data */
	std::string _type;

public:
	AAnimal();
	AAnimal(std::string type);
	AAnimal(const AAnimal& ref);
	virtual	~AAnimal();

	AAnimal&	operator=(const AAnimal& ref);

	const std::string&	getType() const;
	
	virtual	void makeSound() const = 0;
};

#endif
