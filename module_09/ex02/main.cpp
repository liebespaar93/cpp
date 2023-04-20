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

int main(int argc, char const *argv[])
{
	PmergeMe					*PM_ptr = NULL;
	std::vector<std::string>	all_args;
	std::vector<int>			arr;
	if (argc == 1)
	{
		std::cerr << "Error: no argc" << '\n';
		return (1);
	}
	all_args.assign(argv + 1, argv + argc);
	try
	{
		/* code */
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
	PM_ptr->ft_sort_quick();
	PM_ptr->ft_print_sort_data();
	delete PM_ptr;

    return 0;
}

