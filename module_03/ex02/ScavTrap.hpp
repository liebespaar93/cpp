/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:00:40 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/21 14:46:00 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <string>

# include "ClapTrap.hpp"

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
	void		attack(const std::string& target);
	void		guardGate();
};

#endif
