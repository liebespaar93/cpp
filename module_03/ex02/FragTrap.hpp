/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:14:22 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 20:58:20 by kyoulee          ###   ########.fr       */
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
