/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 20:38:27 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/18 09:37:33 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>
# include <exception>

# include "AForm.hpp"

class AForm;

class Bureaucrat
{
private:
	/* data */
	const std::string	_name;
	int					_grade;
	int					_max_grade;
	int					_min_grade;

public:
	Bureaucrat();
	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat& ref);
	~Bureaucrat();

	Bureaucrat&	operator=(const Bureaucrat& ref);

	const std::string&	getName() const;
	int					getGrade() const;

	void	increment();
	void	decrement();
	
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
	
	/* ============= ex01 ============= */
	void	signForm(AForm& ref);

	/* ============= ex02 ============= */
	void executeForm(AForm const & form);
};


std::ostream& operator<<(std::ostream& os, const Bureaucrat& ref);

#endif
