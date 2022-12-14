/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 07:19:43 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 15:21:39 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>


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

//=============================== ex00 ===============================//
	
private:
	/* typedef */
	typedef union u_float_point_fractional_bits
	{
		unsigned int		fractional_bits;
		struct
		{
			unsigned int	frac :_fractional_bits_len ;
			unsigned int	expt :31 - _fractional_bits_len ;
			bool			sign :1 ;
		}	s_bit;
	}	t_float_point_fractional_bits;

	typedef union u_float_point
	{
		float				float_point;
		unsigned int		int_point;
		struct
		{
			unsigned int	frac :23 ;
			unsigned short	expt :8 ;
			bool			sign :1 ;
		}	s_bit;
	}	t_float_point;

public:
	Fixed(const int &value);
	Fixed(const float &value);

	float	toFloat( void ) const;
	int		toInt( void ) const;

};

//====  ex01 ====//
#define FIXED_INFINITY __builtin_huge_valf()
#define FIXED_NAN __builtin_nanf("0x7fc00000")

std::ostream &operator<<(std::ostream &ostream, const Fixed& ref);

#endif
