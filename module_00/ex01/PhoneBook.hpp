/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 18:48:07 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 12:17:10 by kyoulee          ###   ########.fr       */
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
	int			_index;
	Contact		_contact[8];

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
