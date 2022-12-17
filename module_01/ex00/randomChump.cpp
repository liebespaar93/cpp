/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 04:04:19 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 13:52:29 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* newZombie(std::string name);

void randomChump(std::string name)
{
	Zombie	*zombie;
	
	zombie = newZombie(name);
	zombie->announce();
	delete (zombie);
}
