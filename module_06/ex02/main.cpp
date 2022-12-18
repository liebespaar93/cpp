/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:30:22 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/18 11:41:51 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cmath>
#include <exception>
#include <iostream>
#include <unistd.h>
#include <iomanip>

static	int	randNumber(int min, int max)
{
	return ((rand() % max) + min);
}

Base * generate(void)
{
	int		num = randNumber(1, 3);
	Base	*base = NULL;

	try
	{
		if (num == 1)
			base = dynamic_cast<Base *>(new A);
		else if (num == 2)
			base = dynamic_cast<Base *>(new B);
		else if (num == 3)
			base = dynamic_cast<Base *>(new C);
		return (base);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
		return (NULL);
	}
}

void	identify(Base* p)
{
	try
	{
		if (dynamic_cast<A *>(p))
			std::cout << "A" << "\n";
		else if (dynamic_cast<B *>(p))
			std::cout << "B" << "\n";
		else if (dynamic_cast<C *>(p))
			std::cout << "C" << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	identify(Base& p)
{
	try
	{
		if (dynamic_cast<A *>(&p))
			std::cout << "A" << "\n";
		else if (dynamic_cast<B *>(&p))
			std::cout << "B" << "\n";
		else if (dynamic_cast<C *>(&p))
			std::cout << "C" << "\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

int	main(void)
{
    std::cout << std::setfill(' ') << std::left;
	Base * p;
	Base * p1;
	A * p2 = new A;
	Base * p3;

	srand(time(NULL));
	p = generate();
	sleep(1);
	p1 = generate();
	p3 = (dynamic_cast<Base *>(p2));
	
	std::cout << "POINTER" << std::endl;
	identify(p);
	identify(p1);
	identify(p2);
	identify(p3);

	std::cout << "REFERENCE" << std::endl;
	identify(*p);
	identify(*p1);
	identify(*p2);
	identify(*p3);

	delete (p);
	delete (p1);
	delete (p2);
	return (0);
}
