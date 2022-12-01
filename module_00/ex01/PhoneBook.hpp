/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:48:07 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/01 21:17:34 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

# include <Contact.hpp>

class PhoneBook
{
private:
	/* data */ 
	int			index;
	Contact		contact[8];

public:
	PhoneBook();
	~PhoneBook();

	int		&get_index();
	void	contact_add();
	void	search_viewlist();
	void	search_info();
	bool	regex_num(std::string const &str);
};

#endif