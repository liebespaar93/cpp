/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 12:56:39 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/16 06:25:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>
# include <exception>

class Span
{
private:
	/* data */
	std::vector<int>	_vector;
	std::size_t			_size;

public:
	Span();
	Span(const int& size);
	Span(const Span& ref);
	~Span();

	std::size_t&	get_size();
	
	Span&	operator=(const Span& ref);
	int		operator[](const int index);
	
	Span&	addNumber(const int& num);
	Span&	addNumber(const std::vector<int>& vec);
	
	int	shortestSpan();
	int	longestSpan();


	class SegmentFault: public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

};

#endif
