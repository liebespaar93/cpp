/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:49:37 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:38:13 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
private:
	/* data */
	Brain*	_brain;

public:
	Cat();
	Cat(const Cat& ref);
	~Cat();

	Cat&	operator=(const Cat& ref);

	void	makeSound() const;
	
	Brain*	get_brain( void ) const;
};

#endif
