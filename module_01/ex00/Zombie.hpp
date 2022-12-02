/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:39:09 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/02 04:46:54 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>

# define MAX_ZOMBIE 6
# define MAX_ZOMBIE_NAME 6
# define MAX_ZOMBIE_WORD 20

class Zombie
{
private:
	/* data */
	std::string	_name;

public:
	Zombie();
	Zombie(std::string name);
	~Zombie();

	std::string	get_name( void );
	std::string	set_name(std::string name);
	void		announce( void ); 
	std::string	rand_name( void );
	std::string	rand_alphabet(int option);

	std::string	rand_zombie_growls( void );
};

#endif
