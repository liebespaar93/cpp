/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:44:50 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 13:59:46 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>

Zombie *zombieHorde(int N, std::string name);

int	main(void)
{
	int 		size[5] = {10, 4, 1, 0, -1};
	int			len;
	Zombie 		*horde;
	std::string	horde_str;

	len = 0;
	while (len < 5)
	{
		horde_str = "horde_" + std::to_string(size[len]);

		std::cout << "Size: " << size[len] << std::endl;
		horde = zombieHorde(size[len], horde_str);
		std::cout << "Horde: " << horde << std::endl;
		if (horde)
		{
			for (int i = 0; i < size[len]; i++) horde[i].announce();
			delete[](horde);
		}
		std::cout << "========================="<< std::endl;
		len++;
	}
}
