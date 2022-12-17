/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:19:43 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 15:03:32 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed
{
private:
	/* data */
	int					_fractional_bits;
	static const int	_fractional_bits_len = 8;

public:
	Fixed();
	Fixed(const Fixed &ref);
	~Fixed();

	Fixed&	operator=(const Fixed &ref);
	
	int		getRawBits() const;
	void	setRawBits(const int &value);
};

#endif
