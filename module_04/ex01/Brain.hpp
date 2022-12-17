/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 20:25:10 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:38:08 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <string>

class Brain
{
private:
	/* data */
	std::string	_ideas[100];

public:
	Brain();
	Brain(Brain& ref);
	~Brain();

	Brain&	operator=(Brain& ref);

	std::string	*get_ideas();
	void		set_ideas(const std::string& ideas, int index);

};

#endif
