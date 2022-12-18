/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 02:14:36 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/18 11:49:57 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

template<typename T>
void	swap(T &a, T &b)
{
	T	temp;

	temp = a;
	a = b;
	b = temp; 
}

template<typename T>
const T& max(const T& a, const T& b)
{
	if (a > b)
		return (a);
	return (b);
}

template<typename T>
const T& min(const T& a, const T& b)
{
	if (a < b)
		return (a);
	return (b);
}
#endif
