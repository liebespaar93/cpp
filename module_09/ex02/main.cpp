/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 04:50:07 by kyoulee           #+#    #+#             */
/*   Updated: 2023/04/20 13:58:18 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <vector>

#include "PmergeMe.hpp"

#include <unistd.h>

int main(int argc, char const *argv[])
{
	PmergeMe					*PM_ptr = NULL;
	std::vector<std::string>	all_args;

	if (argc == 1)
	{
		std::cerr << "Error: no argc" << '\n';
		return (1);
	}
	// all_args.assign(argv + 1, argv + argc);
	for (int i = 1; argv[i] != NULL; i++)
		all_args.push_back(argv[i]);
	try
	{
		PM_ptr = new PmergeMe(all_args);
	}
	catch(const std::exception& e)
	{
		if (PM_ptr)
			delete PM_ptr;
		std::cerr << e.what() << '\n';
		return (1);
	}
	PM_ptr->ft_print_data();
	PM_ptr->ft_insert_sort();
	PM_ptr->ft_print_sort_data();
	try
	{
		PM_ptr->ft_set_time();
		PM_ptr->ft_insert_sort();
		PM_ptr->ft_diff_time();
	}
	catch(const std::exception& e)
	{
		delete PM_ptr;
		std::cerr << e.what() << '\n';
		return (1);
	}
	try
	{
		PM_ptr->ft_set_time();
		PM_ptr->ft_merge_sort();
		PM_ptr->ft_diff_time();
	}
	catch(const std::exception& e)
	{
		delete PM_ptr;
		std::cerr << e.what() << '\n';
		return (1);
	}
	// try
	// {
	// 	size_t a = atoi(argv[1]);
	// 		PM_ptr->ft_set_time();
	// 	for (size_t i = 0; i < a; i++)
	// 	{
	// 		/* code */
	// 		usleep(10000);
	// 		PM_ptr->ft_diff_time();
	// 	}
		
	// }
	// catch(const std::exception& e)
	// {
	// 	delete PM_ptr;
	// 	std::cerr << e.what() << '\n';
	// 	return (1);
	// }
	delete PM_ptr;

    return 0;
}

