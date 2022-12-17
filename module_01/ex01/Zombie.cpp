/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 00:40:02 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 13:59:49 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Zombie.hpp>
#include <string>

Zombie::Zombie()
{
	this->_name = rand_name();
}

Zombie::Zombie(std::string name)
	: _name(name) {}

Zombie::~Zombie()
{
	std::cout << this->_name << " : dead" << std::endl;
}

std::string	Zombie::get_name() { return (this->_name); }

std::string	Zombie::set_name(std::string name)
{
	this->_name = name;
	return (this->_name); 
}

std::string	Zombie::rand_alphabet(int option)
{
	char ch[2];

	std::string alphabet;
	
	if (option == 1)
		alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	else if (option == 2)
		alphabet = "abcdefghijklmnopqrstuvwxyz";
	else if (option == 3)
		alphabet = "aeiou";
	else
		alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

	ch[0] = alphabet[rand() % alphabet.length()];
	ch[1] = '\0';
	return (ch);
}

std::string	Zombie::rand_name( void )
{
	std::string	name;
	int			name_len;

	name = rand_alphabet(1);
	name_len = rand() % MAX_ZOMBIE_NAME;
	while (name_len--)
	{
		if (name.length() == 3)
			name += rand_alphabet(3);
		else
			name += rand_alphabet(2);
	}
	return (name);
}


std::string	Zombie::rand_zombie_growls()
{
	std::string	growls;
	std::string	word;
	int			word_num;
	int			growls_len;
	int			index;

	growls_len = 0;
	word_num = rand() % 3;
	if (word_num == 0)
		word = "Brainz..";
	else if ( word_num == 1)
		word = "DEATH...";
	else if ( word_num == 2)
		word = "UGHRAH..";
	index = 0;
	growls.clear();
	while (index < 9 && growls_len < MAX_ZOMBIE_WORD)
	{
		if (rand() % 4)
			index++;
		growls += word[index];
		growls_len++;
	}
#ifdef PLAY
	return (growls);
#endif
	return ("BraiiiiiiinnnzzzZ...");

}

void	Zombie::announce()
{
	std::cout
		<< this->_name
		<< " : "
		<< rand_zombie_growls()
		<< std::endl;
}
