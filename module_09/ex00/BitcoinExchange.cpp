/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:25:30 by kyoulee           #+#    #+#             */
/*   Updated: 2023/04/20 04:50:00 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(std::string file_name, std::string delimiter)
{
	std::ifstream	files;
	std::string		str_line;
	size_t			pos = 0;
	std::string		token;

	files.open(file_name);
	if (!files.is_open())
		throw BitcoinError("could not open file.");
	if (std::getline(files, str_line))
	{
		while (!str_line.empty())
		{
			if ((pos = str_line.find(delimiter)) == std::string::npos)
				pos = str_line.length();
			token = str_line.substr(0, pos);
			this->_file_contents.push_back(token);
			str_line.erase(0, pos + delimiter.length());
		}
	}
	while (std::getline(files, str_line))
	{
		std::vector<std::string>	data;
		while (!str_line.empty())
		{
			if ((pos = str_line.find(delimiter)) == std::string::npos)
				pos = str_line.length();
			token = str_line.substr(0, pos);
			data.push_back(token);
			str_line.erase(0, pos + delimiter.length());
		}
		this->_file_data.push_back(data);
	}
	files.close();
	this->ft_file_to_data();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& ref)
{
	this->_file_contents = ref._file_contents;
	this->_file_data = ref._file_data;
	this->_data = ref._data;
}

BitcoinExchange::~BitcoinExchange()
{
    this->_file_data.clear();
    this->_data.clear();
}

BitcoinExchange&	BitcoinExchange::operator=(const BitcoinExchange& ref)
{
	this->_file_contents.clear();
	this->_file_data.clear();
	this->_file_contents.clear();
	this->_file_contents = ref._file_contents;
	this->_file_data = ref._file_data;
	this->_data = ref._data;
    return (*this);
}

void    BitcoinExchange::ft_file_to_data()
{
	struct tm	s_time;
	time_t		t_time;
	std::string	time_str;

	for (std::vector< std::vector<std::string> >::iterator i = this->_file_data.begin(); \
		i != this->_file_data.end(); \
		i++)
	{
		if ((*i).at(0).empty() || (*i).at(1).empty() )
			throw BitcoinError("bad data file. ");
		std::vector<double>	vec_int;
		time_str = (*i).at(0);
		time_str += " 00:00:00";
		memset(&s_time, 0, sizeof(struct tm));
		if (!strptime(time_str.c_str(), "%Y-%m-%d %H:%M:%S", &s_time))
			throw BitcoinError("bad data file.");
		t_time = mktime(&s_time);
		vec_int.push_back(t_time);
		vec_int.push_back(atof((*i).at(1).c_str()));
		this->_data.push_back(vec_int);
	}
}


double	BitcoinExchange::ft_find_coin_price(std::string date)
{
	struct tm	s_time;
	time_t		t_time;

	if (!strptime(date.c_str(), "%Y-%m-%d %H:%M:%S", &s_time))
		throw std::exception();
	t_time = mktime(&s_time);

	for (std::vector< std::vector<double> >::iterator i = this->_data.begin(); \
		i != this->_data.end(); \
		i++)
	{
		if ((*i).at(0) > t_time)
		{
			if (i == this->_data.begin())
				throw std::exception();
			else
				return ((*(i - 1)).at(1));
		}
	}
	return ((*(this->_data.end() - 1)).at(1));
}


void		BitcoinExchange::ft_make_exchange(std::string file_input, std::string delimiter)
{
	std::ifstream	files;
	std::string		str_line;
	std::string		temp;
	size_t			pos = 0;
	std::string		token;
	std::vector<std::string>	data;

	if (this->_data.empty())
		throw BitcoinError("no data");
	files.open(file_input);
	if (!files.is_open())
		throw BitcoinError("could not open file.");
	if (std::getline(files, str_line))
	{
		while (!str_line.empty())
		{
			if ((pos = str_line.find(delimiter)) == std::string::npos)
				pos = str_line.length();
			token = str_line.substr(0, pos);
			str_line.erase(0, pos + delimiter.length());
			data.push_back(token);
		}
	}
	if (data.size() != 2)
		throw BitcoinError("bad input => " + temp);
	while (std::getline(files, str_line))
	{
		data.clear();
		temp = str_line;
		while (!str_line.empty())
		{
			if ((pos = str_line.find(delimiter)) == std::string::npos)
				pos = str_line.length();
			token = str_line.substr(0, pos);
			data.push_back(token);
			str_line.erase(0, pos + delimiter.length());
		}
		try
		{
			if (data.size() != 2)
				throw BitcoinError("bad input => " + temp);
			if (atof(data.at(1).c_str()) < 0)
				throw BitcoinError("not a positive number.");
			if (atof(data.at(1).c_str()) > 1000)
				throw BitcoinError("too large a number.");
			double price = this->ft_find_coin_price(data.at(0) + " 01:00:00");
			std::cout  << data.at(0) << "=>" << data.at(1) << " = " << price * atof(data.at(1).c_str()) << std::endl;
		}
		catch (const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	files.close();
}

BitcoinExchange::BitcoinError::BitcoinError()
	: _message("Error: default")
{

}

BitcoinExchange::BitcoinError::BitcoinError(std::string errormessege)
	: _message("Error: " + errormessege)
{

}

const char* BitcoinExchange::BitcoinError::what() const throw()
{
	return (this->_message.c_str());
}
