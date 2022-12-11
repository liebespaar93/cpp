/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:58:19 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/09 06:25:26 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include "Bureaucrat.hpp"

# include <exception>

class Bureaucrat;

class AForm
{
private:
	/* data */
	static const int	_max_grade = 150;
	static const int	_min_grade = 1;
	const std::string	_name;
	const int			_grade_to_sign;
	const int			_grade_to_execute;
	bool				_signed;

public:
	AForm();
	AForm(std::string name, int grade_to_sign, int grade_to_execute);
	AForm(const AForm& ref);
	virtual	~AForm();

	AForm&	operator=(const AForm& ref);

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

	/* ============= ex02 ============= */
public:
	class	SignedException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	virtual void	execute(Bureaucrat const & executor) const;

};

std::ostream& operator<<(std::ostream& os, const AForm& ref);

#endif
