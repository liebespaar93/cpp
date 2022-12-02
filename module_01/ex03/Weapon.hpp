/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:09:31 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/02 11:32:52 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>

class Weapon
{
	private:
		/* data */
		std::string	_type;

	public:
		Weapon();
		~Weapon();
		Weapon(std::string type);

		std::string	&getType();
		void		setType(std::string type);
};

#endif
