/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:30:22 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/30 15:49:38 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include "D.hpp"


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


	Base	base;
	A		a;
	B		b;
	D		d;

	std::cout << "type_id base name : " << typeid(base).name() << std::endl;
	std::cout << "type_id a name    : " << typeid(a).name() << std::endl;
	std::cout << "type_id b name    : " << typeid(b).name() << std::endl;
	std::cout << "type_id d name    : " << typeid(d).name() << std::endl;
	std::cout << "type_id base <= a : " << typeid(base).before(typeid(a)) << std::endl;
	std::cout << "type_id base <= b : " << typeid(base).before(typeid(b)) << std::endl;
	std::cout << "type_id base <= d : " << typeid(base).before(typeid(d)) << std::endl;
	std::cout << "type_id a <= base : " << typeid(a).before(typeid(base)) << std::endl;
	std::cout << "type_id a <= b    : " << typeid(a).before(typeid(b)) << std::endl;
	std::cout << "type_id a <= d    : " << typeid(a).before(typeid(d)) << std::endl;
	std::cout << "type_id b <= base : " << typeid(b).before(typeid(base)) << std::endl;
	std::cout << "type_id b <= a    : " << typeid(b).before(typeid(a)) << std::endl;
	std::cout << "type_id b <= d    : " << typeid(b).before(typeid(d)) << std::endl;
	std::cout << "type_id d <= base : " << typeid(d).before(typeid(base)) << std::endl;
	std::cout << "type_id d <= a    : " << typeid(d).before(typeid(a)) << std::endl;
	std::cout << "type_id d <= b    : " << typeid(d).before(typeid(b)) << std::endl;


	std::cout << "dynamic_cast base <= a : " << dynamic_cast<Base *>(&a) << std::endl;
	std::cout << "dynamic_cast base <= b : " << dynamic_cast<Base *>(&b) << std::endl;
	//std::cout << "dynamic_cast base <= d : " << dynamic_cast<Base *>(&d) << std::endl;
	std::cout << "dynamic_cast a <= base : " << dynamic_cast<A *>(&base) << std::endl;
	std::cout << "dynamic_cast a <= b    : " << dynamic_cast<A *>(&b) << std::endl;
	//std::cout << "dynamic_cast a <= d    : " << dynamic_cast<A *>(&d) << std::endl;
	std::cout << "dynamic_cast b <= base : " << dynamic_cast<B *>(&base) << std::endl;
	std::cout << "dynamic_cast b <= a    : " << dynamic_cast<B *>(&a) << std::endl;
	//std::cout << "dynamic_cast b <= d    : " << dynamic_cast<B *>(&d) << std::endl;
	std::cout << "dynamic_cast d <= base : " << dynamic_cast<D *>(&base) << std::endl;
	std::cout << "dynamic_cast d <= a    : " << dynamic_cast<D *>(&a) << std::endl;
	std::cout << "dynamic_cast d <= b    : " << dynamic_cast<D *>(&b) << std::endl;

	std::cout << "static_cast base <= a : " << static_cast<Base *>(&a) << std::endl;
	std::cout << "static_cast base <= b : " << static_cast<Base *>(&b) << std::endl;
	// std::cout << "static_cast base <= d : " << static_cast<Base *>(&d) << std::endl;
	std::cout << "static_cast a <= base : " << static_cast<A *>(&base) << std::endl;
	// std::cout << "static_cast a <= b    : " << static_cast<A *>(&b) << std::endl;
	// std::cout << "static_cast a <= d    : " << static_cast<A *>(&d) << std::endl;
	std::cout << "static_cast b <= base : " << static_cast<B *>(&base) << std::endl;
	// std::cout << "static_cast b <= a    : " << static_cast<B *>(&a) << std::endl;
	// std::cout << "static_cast b <= d    : " << static_cast<B *>(&d) << std::endl;
	// std::cout << "static_cast d <= base : " << static_cast<D *>(&base) << std::endl;
	// std::cout << "static_cast d <= a    : " << static_cast<D *>(&a) << std::endl;
	// std::cout << "static_cast d <= b    : " << static_cast<D *>(&b) << std::endl;
	delete (p);
	delete (p1);
	delete (p2);
	return (0);
}
