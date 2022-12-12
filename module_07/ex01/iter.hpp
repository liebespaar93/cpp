/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:42:40 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/13 01:14:52 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

template<typename T>
void iter(T* arr, int lenght, void (*f)(const T&))
{
	for (int i = 0; i < lenght; ++i)
	{
		f(arr[i]);
	}
}

#endif
