/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:37 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 07:03:54 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
private:
	/* data */

public:
	Cat();
	Cat(const Cat& ref);
	~Cat();

	Cat&	operator=(const Cat& ref);

	void	makeSound() const;

};

#endif
