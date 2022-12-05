/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:00:40 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/06 01:42:05 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"

# include <iostream>

class ScavTrap: public ClapTrap
{
private:
	/* data */

public:
	ScavTrap();
	ScavTrap(std::string name);
	ScavTrap(ScavTrap& ref);
	~ScavTrap();

	ScavTrap&   operator=(ScavTrap& ref);
	void	attack(const std::string& target);
	void	guardGate();
};

#endif