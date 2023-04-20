/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 04:50:12 by kyoulee           #+#    #+#             */
/*   Updated: 2023/04/20 04:50:13 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <iostream>
#include <string>
#include <stack>

class RPN
{
private:
    /* data */
    std::stack<double>_num_stack;

public:
    RPN();
    RPN(std::string file_name);
    RPN(const RPN& ref);
    ~RPN();

    RPN&	operator=(const RPN& ref);

    void    ft_caculate_add();
    void    ft_caculate_min();
    void    ft_caculate_mul();
    void    ft_caculate_div();

    std::string ft_get_result();

	class RPNError : public std::exception
	{
		private:
			std::string _message;

		public:
			RPNError();
			RPNError(std::string errormessege);
			virtual ~RPNError() throw() {return ;}

			virtual const char* what() const throw();
	};

};

#endif
