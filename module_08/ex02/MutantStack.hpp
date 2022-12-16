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
