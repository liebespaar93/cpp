/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 18:13:23 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/01 21:43:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Contact.hpp>

#include <iomanip>	// for std::setw
#include <regex>	// for regex_match

Contact::Contact() {}

Contact::~Contact() {}

void Contact::clean()
{
	int	id;

	id = 0;
	while (id < END)
		this->info[id++].clear();
}

void Contact::set_contact(int &index)
{
	int	id;

	id = 0;
	this->info[id++] = std::to_string(index + 1);
	while (id < this->END)
	{
		std::cout << this->enum_guide(id) << " : ";
		std::getline(std::cin, info[id]);
		if (info[id].empty())
			std::cout << this->enum_guide(id) << " is empty" << std::endl;
		else if (info[id].compare("EXIT") == 0)
		{
			this->clean();
			return ;
		}
		else if (id == this->PHONENUMBER)
		{
			if (this->regex_phone(info[id]))
				id++;
			else
				std::cout << this->enum_guide(id) << " ex) 010-1234-5678" << std::endl;
		}
		else
			id++;
	}
	index++;
	this->set_view();
}

std::string	Contact::enum_guide(int index)
{
	if (index == INDEX)
		return ("INDEX");
	else if (index == FIRSTNAME)
		return ("First name");
	else if (index == LASTNAME)
		return ("Last name");
	else if (index == NICKNAME)
		return ("Nick name");
	else if (index == PHONENUMBER)
		return ("Phone number");
	else if (index == DARKEST_SECRET)
		return ("Darkest secret");
	else if (index == END)
		return ("END");
	else
		return ("NULL");
}

bool Contact::regex_phone(std::string const &str)
{
	return (std::regex_match(str, std::regex("[0-9]{2,3}-[0-9]{4}-[0-9]{4}")));
}

void Contact::set_view()
{
	int id;

	id = 0;
	std::cout << "========== info ==========" << std::endl;
	while (id < this->END)
	{
		std::cout << std::left << std::setw(15) << enum_guide(id);
		std::cout << "| " << this->info[id] << std::endl;
		id++;
	}
	std::cout << "========== ---- ==========" << std::endl;
}

void Contact::search_view(int id)
{
	if (info[id].length() > 10)
		std::cout << this->info[id].substr(0, 9) << ".";
	else
		std::cout << std::right << std::setw(10) << this->info[id];
}