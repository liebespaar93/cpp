/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:26:53 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/25 05:07:41 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

struct Data
{
	long n;
};

uintptr_t serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data* deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }

int	main(void)
{
	Data*		data;
	uintptr_t	rawData;
	Data*		retData;

	data = new Data;

	std::cout << "Data             : " << data << std::endl;
	rawData = serialize(data);
	std::cout << "Raw data         : " << rawData << std::endl;
	retData = deserialize(rawData);
	std::cout << "Deserialized data: " << retData << std::endl;

	delete data;

	return (0);
}
