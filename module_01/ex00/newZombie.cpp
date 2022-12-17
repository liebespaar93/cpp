/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 04:04:17 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 13:51:57 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie*	newZombie(std::string name)
{
	Zombie	*zombie;
	
	zombie = new Zombie(name);
	return (zombie);
}
