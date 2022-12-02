/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 05:02:38 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/02 11:31:07 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

# include <iostream>
# include <Weapon.hpp>

class HumanA
{
private:
	/* data */
	std::string	_name;
	Weapon		&_weapon;
	
public:
	~HumanA();
	HumanA(std::string name, Weapon &weapon);
	
	void		attack();
};

#endif
