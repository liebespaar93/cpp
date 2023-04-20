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

std::vector<int> PmergeMe::ft_sort_bubble()
{
	this->_sort_data = this->_data;
	
	for (size_t i = 0; i < this->_sort_data.size(); i++)
	{
		for (size_t j = 0; j < this->_sort_data.size() - i - 1; j++)
		{
			if (this->_sort_data[j] > this->_sort_data[j + 1])
			{
				this->_sort_data[j] += this->_sort_data[j + 1];
				this->_sort_data[j + 1] = this->_sort_data[j] - this->_sort_data[j + 1];
				this->_sort_data[j] -= this->_sort_data[j + 1];
			}
		}
	}
	return (this->_sort_data);
}

int	PmergeMe::partition(std::vector<int> &arr, int l, int r)
{
	int pivot;
	int i, tmp;

	pivot = this->_sort_data[r];
	i = 0;
	for (int j = l; j <= r - 1; j++)
	{
		if (this->_sort_data[j] <= pivot)
		{
			i++;
			tmp = this->_sort_data[i];
			this->_sort_data[i] = this->_sort_data[j];
			this->_sort_data[j] = tmp;
		}
	}
	tmp = this->_sort_data[i + 1];
	this->_sort_data[i + 1] = this->_sort_data[r];
	this->_sort_data[r] = tmp;
	return (i + 1);
}

void	PmergeMe::quick_sort(std::vector<int> &arr, int L, int R)
{
	int	p;
	
	if (L < R)
	{
		p = this->partition(arr, L, R);
		quick_sort(arr, L, p - 1);
		quick_sort(arr, p + 1, R);
	}
}

void	PmergeMe::ft_sort_quick()
{
	this->_sort_data = this->_data;
	this->quick_sort(this->_sort_data, 0, this->_sort_data.size());
}
