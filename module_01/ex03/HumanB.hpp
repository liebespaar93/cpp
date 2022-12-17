/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:02:46 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 14:12:56 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

# include <string>
# include "Weapon.hpp"

class HumanB
{
private:
	/* data */
	std::string	_name;
	Weapon		*_weapon;

public:
	HumanB(std::string name);
	~HumanB();

	void		setWeapon(Weapon &weapon);
	void		attack();
};

#endif
