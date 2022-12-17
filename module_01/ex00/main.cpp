/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:44:50 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 13:52:21 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <ctime>

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie	*zombies[MAX_ZOMBIE];
	Zombie	*zombie;
	int		zombie_num;

	zombie_num = 0;
	zombie = newZombie("admin");
	zombie->announce();
	while (rand() % (MAX_ZOMBIE - zombie_num))
	{
		srand(time(NULL) + zombie_num);
		zombies[zombie_num] = new Zombie;
		zombies[zombie_num]->announce();
		zombie_num++;
	}
	while (zombie_num--)
	{
		delete zombies[zombie_num];
	}
	zombie->set_name(zombie->rand_name());
	randomChump(zombie->get_name());
	zombie->set_name(zombie->rand_name());
	delete (zombie);
	return (0);
}
