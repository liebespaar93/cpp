/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 06:12:45 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/12 07:05:09 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <string>
# include <exception>
# include "AForm.hpp"

class AForm;

class Intern
{
private:
	/* data */

public:
	Intern();
	Intern(const Intern& ref);
	~Intern();

	Intern&	operator=(const Intern& ref);

	class Exception : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	AForm	*makeForm(std::string name, std::string target);

};

#endif
