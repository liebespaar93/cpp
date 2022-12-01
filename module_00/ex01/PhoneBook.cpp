/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 15:49:53 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/01 21:28:45 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <PhoneBook.hpp>

#include <regex>

PhoneBook::PhoneBook() {this->index = 0;}

PhoneBook::~PhoneBook() {}

int &PhoneBook::get_index() { return (this->index); }

void	PhoneBook::contact_add()
{
	contact[this->index].set_contact(this->index);
}

void	PhoneBook::search_viewlist()
{
	int	index;

	index = 0;
	std::cout << "╔══════════════════════════════════════════════════╗" << std::endl;
	std::cout << "║   index   | first name | last name  |  nickname  ║" << std::endl;
	std::cout << "╠══════════════════════════════════════════════════╣" << std::endl;
	while (index < this->index)
	{
		std::cout << "║";
		this->contact[index].search_view(contact->INDEX);
		std::cout << " | ";
		this->contact[index].search_view(contact->FIRSTNAME);
		std::cout << " | ";
		this->contact[index].search_view(contact->LASTNAME);
		std::cout << " | ";
		this->contact[index].search_view(contact->NICKNAME);
		std::cout << " ║" << std::endl;
		index++;
	}
	std::cout << "╚══════════════════════════════════════════════════╝" << std::endl;
}

bool PhoneBook::regex_num(std::string const &str)
{
	return (std::regex_match(str, std::regex("[(-|+)]?[0-9]")));
}

void	PhoneBook::search_info()
{
	std::string	cmd;
	int			cmd_num;
	int			chance;

	if (this->get_index() == 0)
		return ;
	chance = 3;
	while (chance--)
	{
		std::cout << "index : ";
		std::getline(std::cin, cmd);
		if (cmd.compare("EXIT") == 0)
				exit(0);
		if (this->regex_num(cmd))
		{
			cmd_num = atoi(cmd.c_str());
			if (0 < cmd_num && cmd_num <= this->index)
			{
				this->contact[cmd_num - 1].set_view();
				return ;
			}
			else
				std::cout << "out of index" << std::endl;
		}
		else
			std::cout << "input number of index" << std::endl;
	}
}