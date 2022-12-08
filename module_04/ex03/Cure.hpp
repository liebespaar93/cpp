/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 18:45:25 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 18:51:10 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
# define CURE_HPP

#include "AMateria.hpp"

class Cure: public AMateria
{
private:
	/* data */

public:
	Cure();
	Cure(const Cure& ref);
	~Cure();

	Cure&	operator=(const Cure& ref);

	AMateria*	clone() const;
	void		use(ICharacter& target);
};

#endif
