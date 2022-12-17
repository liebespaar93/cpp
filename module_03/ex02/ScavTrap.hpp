/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 08:00:40 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 20:59:09 by kyoulee          ###   ########.fr       */
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
	void	attack(const std::string& target);
	void	guardGate();
};

#endif
