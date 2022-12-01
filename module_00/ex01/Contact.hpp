/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 22:06:06 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/01 22:03:05 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
public:
	/* enum */
	enum EContact
	{
		INDEX,
		FIRSTNAME,
		LASTNAME,
		NICKNAME,
		PHONENUMBER,
		DARKEST_SECRET,
		END
	};

private:
	/* data */ 
	std::string	info[END];

public:
	Contact();
	~Contact();
	
	std::string	enum_guide(int index);
	
	void		clean();

	void		set_contact(int &id);
	void		set_view();

	void		search_view(int id);
	bool		regex_phone(std::string const &str);
};


#endif