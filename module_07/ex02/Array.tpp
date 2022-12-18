/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 06:19:49 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/18 12:22:40 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
# define ARRAY_TPP

# include <iostream>
# include <exception>

template <typename T>
Array<T>::Array():
	_head(NULL)
{ }

template <typename T>
Array<T>::Array(std::size_t size):
	_head(new T[size]),
	_size(size)
{ }

template <typename T>
Array<T>::Array(const Array& ref):
	_head(new T[ref.size()]),
	_size(ref.size())
{
	*this = ref;
}

template <typename T>
Array<T>::~Array()
{
	delete[] (this->_head);
}

template <typename T>
Array<T>&	Array<T>::operator=(const Array<T>& ref)
{
	if (this->_head == ref._head)
		return (*this);
	if (this->_head)
		delete [] this->_head;
	this->_head = new T[ref._size];
	this->_size = ref._size;
	for (std::size_t i = 0; i < this->_size; i++)
		this->_head[i] = ref._head[i];
	return (*this);
}

template <typename T>
T&	Array<T>::operator[](std::size_t index)
{
	if (0 <= index && index < this->size())
		return (this->_head[index]);
	else
		throw Array::SegmentFault();
}

template <typename T>
const T&	Array<T>::operator[](std::size_t index) const
{
	if (0 <= index && index < _size)
		return (this->_head[index]);
	else
		throw Array::SegmentFault();
}

template <typename T>
std::size_t Array<T>::size() const 
{
	return this->_size;
}

template <typename T>
const char*	Array<T>::SegmentFault::what() const throw()
{
	return ("Segment Fault");
}

#endif
