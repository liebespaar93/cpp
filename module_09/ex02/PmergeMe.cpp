/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 05:08:31 by kyoulee           #+#    #+#             */
/*   Updated: 2023/04/20 14:00:50 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	std::cout << std::setw(15) << "[PmergeMe] " << "create!!" << std::endl;
}

PmergeMe::PmergeMe(std::vector<std::string> argv_str)
{
	int num;

	for (std::vector<std::string>::iterator i = argv_str.begin(); \
		i != argv_str.end(); \
		i++)
	{
		std::string::const_iterator it = (*i).begin();
		while (it != (*i).end() && std::isdigit(*it))
			++it;
		if (!(*i).empty() && it != (*i).end())
			throw std::exception();
		try
		{
			num = std::stoi((*i).c_str());
			if (num < 0)
				throw std::exception();
		}
		catch ( ... )
		{
			throw ;
		}
		this->_data.push_back(num);
	}
}
 
PmergeMe::PmergeMe(const PmergeMe& ref)
{
	*this=ref;
}
 
PmergeMe::~PmergeMe()
{
	std::cout << std::setw(15) << "[PmergeMe] " << "delete!!" << std::endl;
}
 
PmergeMe&	PmergeMe::operator=(const PmergeMe& ref)
{
	this->_data = ref._data;
	return (*this);
}

void	PmergeMe::ft_print_data()
{
	std::cout << "Before:\t";
	for (std::vector<int>::iterator i = this->_data.begin(); \
		i != this->_data.end(); \
		i++)
	{
		std::cout << (*i) << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::ft_print_sort_data()
{
	std::cout << "Before:\t";
	for (std::vector<int>::iterator i = this->_sort_data.begin(); \
		i != this->_sort_data.end(); \
		i++)
	{
		std::cout << (*i) << " ";
	}
	std::cout << std::endl;
}

void	PmergeMe::ft_insert_sort()
{
	int		point;

	this->_sort_data = this->_data;
	for (size_t i = 0; i < this->_sort_data.size(); i++)
	{
		for (size_t j = 0; j < i; j++)
		{
			if (this->_sort_data[i] < this->_sort_data[j])
			{
				point = this->_sort_data[i];
				for (size_t k = i; k > j; k--)
					this->_sort_data[k] = this->_sort_data[k - 1];
				this->_sort_data[j] = point;
				j = i;
			}
		}
	}
}

void	PmergeMe::ft_merge_sort(int L, int R)
{
	int	mid;

	if (L >= R)
		return;
	mid = (L + R) / 2;
	this->ft_merge_sort(L, mid);
	this->ft_merge_sort(mid + 1, R);

	
	std::vector<int> result;
	for (int i = L, j = mid + 1; i <= mid || j <= R;)
	{
		if (i > mid)
			result.push_back(this->_sort_data[j++]);
		else if (j > R || this->_sort_data[i] <= this->_sort_data[j])
			result.push_back(this->_sort_data[i++]);
		else
			result.push_back(this->_sort_data[j++]);
	}
	for (int i = L, j = 0; i <= R; i++, j++)
		this->_sort_data[i] = result[j];
}

void	PmergeMe::ft_merge_sort()
{
	this->_sort_data = this->_data;
	this->ft_merge_sort(0, this->_sort_data.size() - 1);
}

void	PmergeMe::ft_set_time()
{
	if (clock_gettime(CLOCK_MONOTONIC, &this->_time) == -1)
		throw std::exception();
}

void	PmergeMe::ft_diff_time()
{
    struct timespec		diff;
	long long			us_diff;
	
	if (clock_gettime(CLOCK_MONOTONIC, &diff) == -1)
		throw std::exception();
	us_diff = diff.tv_nsec - this->_time.tv_nsec;
	us_diff /= 10000;
	if (us_diff < 0)
		us_diff += 100000;
	std::cout << "Time to process a range of " 
		<< this->_sort_data.size() 
		<< " elements with std::[..] : "
		<< diff.tv_sec - this->_time.tv_sec
		<< "."
		<< std::setw(5) << std::setfill('0') << us_diff
		<< " μs"
		<< std::setw(0) << std::setfill(' ') 
		<< std::endl;
}
