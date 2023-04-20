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

	int		partition(std::vector<int> &arr, int l, int r);
	void	quick_sort(std::vector<int> &arr, int L, int R);
	
public:
	PmergeMe();
	PmergeMe(std::vector<std::string> argv_str);
	PmergeMe(const PmergeMe& ref);
	~PmergeMe();

	PmergeMe&	operator=(const PmergeMe& ref);

	void				ft_print_data();
	void				ft_print_sort_data();
	std::vector<int>	ft_sort_bubble();
	void				ft_sort_quick();
};

#endif
