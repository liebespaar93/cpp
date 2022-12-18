/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 15:02:27 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/18 15:02:31 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <algorithm>
# include <deque>

template <typename T>
class MutantStack : public std::stack<T>
{
private:
	/* data */
	
public:
	MutantStack():
		MutantStack<T>::stack()
		{}

	MutantStack(MutantStack const & ref):
		MutantStack<T>::stack(ref)
		{ *this = ref; };

	~MutantStack() {};

	MutantStack<T>&	operator=(const MutantStack<T>& ref) 
	{
		if (this != &ref)
		{
			MutantStack<T>::stack::operator=(ref);
		}
		return *this;
	}

	typedef typename MutantStack<T>::stack::container_type::iterator iterator;

	iterator begin()
	{
		return this->c.begin();
	}

	iterator end()
	{
		return this->c.end();
	}

};

#endif
