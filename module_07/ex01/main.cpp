/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 00:52:36 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/18 11:53:55 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <sstream>

#include "iter.hpp"

template <typename T>
void	ft_std_print(const T& ptr)
{
	std::cout << ptr << std::endl;
}

int main(void)
{
	std::string	string_arr[10];
	const char	*str_arr[10];
	char	char_arr[10];
	int		int_arr[10];
	std::ostringstream temp;

	for (int i = 0; i < 10; i++)
	{
		string_arr[i] = std::to_string(i);
		str_arr[i] = "abcd213";
		char_arr[i] = 'A' + i;
		int_arr[i] = i;
	}
	std::cout << "========== string_arr ==========" << std::endl;
	::iter(string_arr, 10, ft_std_print);
	std::cout << "========== str_arr ==========" << std::endl;
	::iter(str_arr, 10, ft_std_print);
	std::cout << "========== char_arr ==========" << std::endl;
	::iter(char_arr, 10, ft_std_print);
	std::cout << "========== int_arr ==========" << std::endl;
	::iter(int_arr, 10, ft_std_print);

	return 0;
}
