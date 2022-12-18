/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:58:19 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/18 08:52:32 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <exception>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	/* data */
	const std::string	_name;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
	bool				_signed;

public:
	Form();
	Form(std::string name, int grade_to_sign, int grade_to_execute);
	Form(const Form& ref);
	~Form();

	Form&	operator=(const Form& ref);

	const std::string&	get_name() const;
	int					get_grad_to_sign() const;
	int					get_grad_to_execute() const;
	bool				get_signed() const;

	void		set_signed(bool sign);
	
	class	GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	class	GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	void	beSigned(const Bureaucrat& ref);
};

std::ostream& operator<<(std::ostream& os, const Form& ref);

#endif
