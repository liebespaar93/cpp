#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

# include "AMateria.hpp"
# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
private:
	/* data */
	static const int _max_skill = 4;
	AMateria	*_skill[MateriaSource::_max_skill];
	int			_idx;

public:
	MateriaSource();
	MateriaSource(const MateriaSource& ref);
	~MateriaSource();

	MateriaSource&	operator=(const MateriaSource& ref);

	void		learnMateria(AMateria* ref);
	AMateria*	createMateria(std::string const & type);
};

#endif
