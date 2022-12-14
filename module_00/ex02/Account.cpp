/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 13:00:22 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 13:43:56 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <ctime>
#include <iomanip>

#include "Account.hpp"

/* public */

int	Account::getNbAccounts( void ) { return (_nbAccounts); }
int	Account::getTotalAmount( void ) { return (_totalAmount); }
int	Account::getNbDeposits( void ) { return (_totalNbDeposits); }
int	Account::getNbWithdrawals( void ) { return (_totalNbWithdrawals); }

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout 
		<< "accounts:" << _nbAccounts << ";"
		<< "total:" << _totalAmount << ";"
		<< "deposits:" << _totalNbDeposits << ";"
		<< "withdrawals:" << _totalNbWithdrawals << std::endl;
}

Account::Account(int initialDeposit)
{
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = initialDeposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_totalAmount += initialDeposit;

	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
}

Account::~Account()
{
	this->_nbAccounts--;

	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "closed" << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	this->_amount += deposit;
	this->_totalAmount += deposit;
	this->_totalNbDeposits++;

	_displayTimestamp();
	std::cout 
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount - deposit << ";"
		<< "deposit:" << deposit << ";"
		<< "amount:" << this->_amount << ";"
		<< "nb_deposits:" << ++_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "p_amount:" << this->_amount << ";";

	if (this->_amount - withdrawal > 0)
	{
		this->_amount -= withdrawal;
		this->_totalAmount -= withdrawal;
		this->_totalNbWithdrawals++;

		std::cout
			<< "withdrawal:" << withdrawal << ";"
			<< "amount:" << this->_amount << ";"
			<< "nb_withdrawals:" << ++this->_nbWithdrawals << std::endl;
		return (true);
	}
	else
	{
		std::cout << "withdrawal:" << "refused" << std::endl;
		return (false);
	}
}

int		Account::checkAmount( void ) const
{
	return (_amount);
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "deposits:" << this->_nbDeposits << ";"
		<< "withdrawals:" << this->_nbWithdrawals << std::endl;
}

/* private */
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
	time_t time_now = time(NULL);
	struct tm *now = localtime(&time_now);

	std::cout
		<< '['
		<< std::setfill('0')
		<< std::setw(4) << (now->tm_year + 1900)
		<< std::setw(2) << now->tm_mon + 1
		<< std::setw(2) << now->tm_mday
		<< "_"
		<< std::setw(2) << now->tm_hour
		<< std::setw(2) << now->tm_min
		<< std::setw(2) << now->tm_sec
		<< "] ";
}

Account::Account() {
	this->_accountIndex = this->_nbAccounts++;
	this->_amount = 0;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;

	this->_displayTimestamp();
	std::cout
		<< "index:" << this->_accountIndex << ";"
		<< "amount:" << this->_amount << ";"
		<< "created" << std::endl;
}
