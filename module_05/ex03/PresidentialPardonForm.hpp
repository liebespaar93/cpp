/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 02:48:15 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/18 09:38:37 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <string>

# include "AForm.hpp"

class PresidentialPardonForm: public AForm
{
private:
	/* data */
	std::string	_target;

public:
	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm& ref);
	~PresidentialPardonForm();

	PresidentialPardonForm&	operator=(const PresidentialPardonForm& ref);

	std::string	get_target() const;
	void		set_target(std::string target);

	void	execute(Bureaucrat const & executor) const;
};

#endif
