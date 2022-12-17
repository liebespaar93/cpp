/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:09:31 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 14:11:34 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <string>

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
