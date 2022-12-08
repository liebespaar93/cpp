#include <iostream>
#include <iomanip>

#include "Ice.hpp"

Ice::Ice():
	AMateria("ice")
{
}

Ice::Ice(const Ice& ref):
	AMateria("ice")
{
	this->_type = ref._type;
}

Ice::~Ice()
{
}

Ice&	Ice::operator=(const Ice& ref)
{
	this->_type = ref._type;
	return (*this);
}

AMateria* Ice::clone() const
{
	return (new Ice(*this));
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
