/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:37 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:37:45 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
private:
	/* data */

public:
	WrongCat();
	WrongCat(const WrongCat& ref);
	~WrongCat();

	WrongCat&	operator=(const WrongCat& ref);

	void	makeSound() const;
};

#endif
