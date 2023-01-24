/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 12:47:06 by dpoveda-          #+#    #+#             */
/*   Updated: 2023/01/25 02:08:34 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << std::setfill(' ') << std::left;
	std::cout << "\n========== BUREAUCRAT ==========\n" << std::endl;

	Bureaucrat *A = new Bureaucrat("A", 2);
	try {
		std::cout << "1: " << *A << std::endl;
		A->increment();
		std::cout << "2: " << *A << std::endl;
		A->increment();
		std::cout << "3: " << *A << std::endl;
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
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	delete C;

	std::cout << std::endl;

	try {
		Bureaucrat yudo("Yudo", 151);
		std::cout << "HELLO WORLD!!!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	try {
		Bureaucrat yudo("Yudo", -1);
		std::cout << "HELLO WORLD!!!" << std::endl;
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n========== FORM ==========\n" << std::endl;

	Bureaucrat* poor = new Bureaucrat("Poor", 130);
	Bureaucrat* rich = new Bureaucrat("Rich", 15);
	Form* budgets = new Form("budgets", 30, 10);

	std::cout << std::endl;

	std::cout << *budgets;
	std::cout << std::endl;
	try {
		poor->signForm(*budgets);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	try {
		rich->signForm(*budgets);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	std::cout << *budgets;

	std::cout << std::endl;

	try {
		budgets->beSigned(*poor);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}
	
	try {
		budgets->beSigned(*rich);
	} catch (std::exception& e) {
		std::cout << e.what() << std::endl;
	}

	std::cout << std::endl;

	delete poor;
	delete rich;
	delete budgets;

	system("leaks a.out");
	return 0;
}
