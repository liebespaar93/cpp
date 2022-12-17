/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 08:23:52 by intra42           #+#    #+#             */
/*   Updated: 2022/12/18 06:50:20 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

# include <string>

class Character: public ICharacter
{
private:
	/* data */
	std::string			_name;
	static const int	_max_inventory = 4;
	AMateria			*_inventory[Character::_max_inventory];
	int					_idx;

public:
	Character();
	Character(const std::string& name);
	Character(const Character& ref);
	~Character();

	Character&	operator=(const Character& ref);
	std::string const & getName() const;
	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);
};

#endif
