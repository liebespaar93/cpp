/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:27:11 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/12 21:27:11 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <string>

class Convert
{
private:
	/* data */
	std::string	_str;
public:
	Convert();
	Convert(std::string str);
	Convert(const Convert& ref);
	~Convert();

	Convert&	operator=(const Convert& ref);

	void	convert(const std::string str);

	const std::string	to_char();
	const std::string	to_int();
	const std::string	to_float();
	const std::string	to_double();

};

#endif
