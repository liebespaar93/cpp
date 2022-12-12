/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:13:35 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/13 06:19:34 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <exception>

template <typename T>
class Array
{
private:
	/* data */
	T* _head;
	std::size_t _size;

public:
	Array();
	Array(std::size_t size);
	Array(const Array& ref);
	~Array();
	
	Array&	operator=(const Array<T>& ref);
	T&			operator[](std::size_t index);
	const T&	operator[](std::size_t index) const;
	
	std::size_t size() const;

	class SegmentFault : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

};

#include "Array.tpp"

#endif
