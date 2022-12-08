/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:00 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 19:14:44 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

#include "AMateria.hpp"

class Ice: public AMateria
{
private:
	/* data */

public:
	Ice();
	Ice(const Ice& ref);
	~Ice();

	Ice&	operator=(const Ice& ref);

	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif
