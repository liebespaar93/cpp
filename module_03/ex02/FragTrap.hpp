/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:14:22 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/06 01:45:22 by intra42          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
private:
	/* data */

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap& ref);
	~FragTrap();

	FragTrap&   operator=(FragTrap& ref);

	void    highFivesGuys(void);
};


#endif