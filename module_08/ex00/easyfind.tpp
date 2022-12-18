/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 06:38:16 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/18 13:02:58 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_TPP
# define EASYFIND_TPP

#include <iostream>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T& container, int value)
{
	typename T::iterator	iter;

	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end()) 
	{
		throw std::runtime_error("value is not in this container");
	}
	return iter;
}

#endif
