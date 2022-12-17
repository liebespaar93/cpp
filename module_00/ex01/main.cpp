/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:19:16 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 12:19:52 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "PhoneBook.hpp"

int main(void)
{
	std::string	cmd;
	PhoneBook	phonebook;

	phonebook.get_index();
	std::cout << "phone book v1.0 [" << phonebook.get_index() << "] : ";
	while (std::getline(std::cin, cmd))
	{
		if (cmd.compare("ADD") == 0)
		{
			if (phonebook.get_index() < 8)
				phonebook.contact_add();
			else
				std::cout << "Can't write more then 8 list" << std::endl;
		}
		else if (cmd.compare("SEARCH") == 0)
		{
			phonebook.search_viewlist();
			phonebook.search_info();
		}
		else if (cmd.compare("EXIT") == 0)
			exit(0);
		else if (cmd.compare("HELP") == 0)
		{
			std::cout << "===== guide =====" << std::endl;
			std::cout << "ADD    : write phonebook info " << std::endl;
			std::cout << "SEARCH : view list and select INDEX" << std::endl;
			std::cout << "EXIT   : EXIT Process (0)" << std::endl;
			std::cout << "===== ----- =====" << std::endl;
		}
		else
			std::cout << "need help? write HELP command" << std::endl;
		std::cout << "phone book v1.0 [" << phonebook.get_index() << "] : ";
	}
}
