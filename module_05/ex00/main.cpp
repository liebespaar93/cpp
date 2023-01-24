/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:47:06 by dpoveda-          #+#    #+#             */
/*   Updated: 2023/01/25 02:08:14 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include <iostream>
#include <iomanip>

int main() {

    std::cout << std::setfill(' ') << std::left;

	Bureaucrat *A = new Bureaucrat("A", 2);
	try {
		std::cout << "1: " << *A << std::endl;
		A->increment();
		std::cout << "2: " << *A << std::endl;
		A->increment();
		std::cout << "3: " << *A << std::endl;
		A->increment();
		std::cout << "4: " << *A << std::endl;
		A->increment();
		std::cout << "4: " << *A << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete A;

	std::cout << std::endl;

	Bureaucrat *B = new Bureaucrat("B", 10);
	try {
		std::cout << "1: " << *B << std::endl;
		B->increment();
		std::cout << "2: " << *B << std::endl;
		B->increment();
		std::cout << "3: " << *B << std::endl;
		B->increment();
		std::cout << "4: " << *B << std::endl;
		B->increment();
		std::cout << "5: " << *B << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete B;

	std::cout << std::endl;

	Bureaucrat *C = new Bureaucrat("C", 145);
	try {
		std::cout << "1: " << *C << std::endl;
		C->decrement();
		std::cout << "2: " << *C << std::endl;
		C->decrement();
		std::cout << "3: " << *C << std::endl;
		C->decrement();
		std::cout << "4: " << *C << std::endl;
		C->decrement();
		std::cout << "5: " << *C << std::endl;
		C->decrement();
		std::cout << "6: " << *C << std::endl;
		C->decrement();
		std::cout << "7: " << *C << std::endl;
		C->decrement();
		std::cout << "8: " << *C << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete C;

	std::cout << std::endl;

	try {
		Bureaucrat yudo("Yundo", 151);
		std::cout << "HELLO WORLD!!!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat yudo("Yundo", -1);
		std::cout << "HELLO WORLD!!!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	system("leaks a.out");
	return 0;
}
