/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:07:27 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 14:44:02 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CPP
# define HARL_CPP

# include <iostream>

class Harl
{
public:
	/* enum */
	enum EHarl
	{
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		END
	};

private:
	/* data */

	void debug( void );
	void info( void );
	void warning( void );
	void error( void );

public:
	Harl();
	~Harl();
	
	void complain( std::string level );
    typedef void (Harl::*f)();
};

#endif
