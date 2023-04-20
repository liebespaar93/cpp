/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 02:25:28 by kyoulee           #+#    #+#             */
/*   Updated: 2023/04/20 04:50:02 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

#include <iostream>
#include <vector>

class	BitcoinExchange
{
private:
	/* data */
	std::vector<std::string>					_file_contents;
	std::vector< std::vector<std::string> >		_file_data;
	std::vector< std::vector<double> >			_data;

public:

	BitcoinExchange();
	BitcoinExchange(std::string file_name, std::string delimiter);
	BitcoinExchange(const BitcoinExchange& ref);
	~BitcoinExchange();

	BitcoinExchange&	operator=(const BitcoinExchange& ref);

	void	ft_file_to_data();

	double	ft_find_coin_price(std::string date);

	void	ft_make_exchange(std::string file_input, std::string delimiter);


	
	class BitcoinError : public std::exception
	{
		private:
			std::string _message;

		public:
			BitcoinError();
			BitcoinError(std::string errormessege);
			virtual ~BitcoinError() throw() {return ;}

			virtual const char* what() const throw();
	};
};

#endif
