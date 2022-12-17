/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 04:37:25 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/17 14:02:18 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "string address    : " << &string << std::endl;
	std::cout << "stringPTR address : " << stringPTR << std::endl;
	std::cout << "stringREF address : " << &stringREF << std::endl;

	std::cout << "using string    : " << string << std::endl;
	std::cout << "using stringPTR : " << *stringPTR << std::endl;
	std::cout << "using stringREF : " << stringREF << std::endl;

	return (0);
}
