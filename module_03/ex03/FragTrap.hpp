/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 09:14:22 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 21:12:10 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
private:
	/* data */

public:
	FragTrap();
	FragTrap(std::string name);
	FragTrap(FragTrap& ref);
	virtual ~FragTrap();

	FragTrap&   operator=(FragTrap& ref);

	void    highFivesGuys(void);
};

#endif
