/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: intra42 <intra42@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:37 by intra42           #+#    #+#             */
/*   Updated: 2022/12/08 02:28:22 by intra42          ###   ########.fr       */
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
