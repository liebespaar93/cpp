/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 04:14:14 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 13:59:51 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie *zombieHorde(int N, std::string name)
{
	Zombie *horde;

	if (N <= 0)
		return (NULL);
	horde = new (std::nothrow) Zombie[N];
	if (!horde)
		return (NULL);
	for (int i = 0; i < N; i++)
	{
		horde[i].set_name(name);
	}
	return (horde);
}
