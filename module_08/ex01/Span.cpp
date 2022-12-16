#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include "Span.hpp"

Span::Span()
{ }

Span::Span(const int& size):
	_size(size)
{ 
	this->_vector.empty();
}

Span::Span(const Span& ref):
	_vector(ref._vector),
	_size(ref._size)
{ }

Span::~Span()
{ }


std::size_t&	Span::get_size()
{
	return (this->_size);
}

Span&	Span::operator=(const Span& ref)
{
	this->_size = ref._size;
	this->_vector = ref._vector;
	return (*this);
}

int	Span::operator[](const int index)
{\
	return (this->_vector[index]);
}

Span&	Span::addNumber(const int& num)
{
	if (_vector.size() < this->_size)
		_vector.push_back(num);
	else
		throw Span::SegmentFault();
	return (*this);
}

int	Span::shortestSpan()
{
	int min;
	
	min = this->longestSpan();
	for (std::size_t i = 0; i < _vector.size(); i++)
	{
		for (std::size_t k = i + 1; k < _vector.size(); k++)
		{
			if (_vector[i] > _vector[k])
			{
				min = min < _vector[i] - _vector[k] ? min : _vector[i] - _vector[k];
			}
			else
			{
				min = min < _vector[k] - _vector[i] ? min : _vector[k] - _vector[i];
			}
		}
	}
	return (min);
}

int	Span::longestSpan()
{
	int max;

	max = 0;
	for (std::size_t i = 0; i < _vector.size(); i++)
	{
		for (std::size_t k = i + 1; k < _vector.size(); k++)
		{
			if (_vector[i] > _vector[k])
			{
				max = max > _vector[i] - _vector[k] ? max : _vector[i] - _vector[k];
			}
			else
			{
				max = max > _vector[k] - _vector[i] ? max : _vector[k] - _vector[i];
			}
		}
	}
	return (max);
}

Span&	Span::addNumber(const std::vector<int>& vec)
{
	if (this->_vector.size() + std::distance(vec.begin(), std::max_element(vec.begin(), vec.end())) < this->_size)
	{
		for (std::size_t i = 0; i < vec.size(); i++)
			this->_vector.push_back(vec[i]);
	}
	else
		throw Span::SegmentFault();
	return (*this);
}


const char* Span::SegmentFault::what() const throw() { return ("Span out of lenght!!"); }
