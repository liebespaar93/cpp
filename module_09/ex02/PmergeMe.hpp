/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 05:08:28 by kyoulee           #+#    #+#             */
/*   Updated: 2023/04/20 14:00:06 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <string>
#include <vector>

class PmergeMe
{
private:
	/* data */
	std::vector<int>    _data;
	std::vector<int>	_sort_data;
    struct timespec		_time;

	void	ft_merge_sort(int L, int R);
	
public:
	PmergeMe();
	PmergeMe(std::vector<std::string> argv_str);
	PmergeMe(const PmergeMe& ref);
	~PmergeMe();

	PmergeMe&	operator=(const PmergeMe& ref);

	void	ft_print_data();
	void	ft_print_sort_data();
	void	ft_insert_sort();
	void	ft_merge_sort();
	void	ft_set_time();
	void	ft_diff_time();

};

#endif
