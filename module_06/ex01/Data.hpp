#ifndef DATA_HPP
# define DATA_HPP

class Data
{
private:
	/* data */
	long	ptr;

public:
	Data();
	Data(const Data& ref);
	~Data();

	Data&	operator=(const Data& ref);
};

#endif
