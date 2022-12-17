/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 19:38:04 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:41:50 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

#include <string>

#include "ICharacter.hpp"

class ICharacter;

class AMateria
{
protected:
	std::string	_type;
	//[...]

public:
	AMateria();
	AMateria(std::string const & type);
	AMateria(const AMateria& ref);
	virtual	~AMateria();

	AMateria&	operator=(const AMateria& ref);
	//[...]
	
	std::string const & getType() const; //Returns the materia type

	virtual AMateria* clone() const = 0;
	virtual void use(ICharacter& target);
};
#endif
