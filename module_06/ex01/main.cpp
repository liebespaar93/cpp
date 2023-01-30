/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:26:53 by kyoulee           #+#    #+#             */
/*   Updated: 2023/01/30 15:16:08 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <stdint.h>

#include "Data.hpp"

uintptr_t serialize(Data *ptr) { return reinterpret_cast<uintptr_t>(ptr); }

Data* deserialize(uintptr_t raw) { return reinterpret_cast<Data*>(raw); }

int	main(void)
{
	Data data;
	Data* data_ptr;
	uintptr_t raw_data;
	uintptr_t raw_ptr_data;
	Data* ret_data;
	Data* ret_ptr_Data;
	
	data_ptr = new Data();

	std::cout << "Data             : " << &data << std::endl;
	
	std::cout << "Dat_ptr          : " << data_ptr << std::endl;

	raw_data = serialize(&data);
	raw_ptr_data = serialize(data_ptr);
	std::cout << "Raw data         : " << raw_data << std::endl;
	std::cout << "Raw_ptr data     : " << raw_ptr_data << std::endl;
	ret_data = deserialize(raw_data);
	ret_ptr_Data = deserialize(raw_ptr_data);
	std::cout << "Deserialized data: " << ret_data << std::endl;
	std::cout << "Deserialized data: " << ret_ptr_Data << std::endl;
	std::cout << "type_id  : " << typeid(data).name() << std::endl;
	std::cout << "type_id  : " << typeid(&data).name() << std::endl;
	std::cout << "type_id  : " << typeid(data_ptr).name() << std::endl;
	std::cout << "type_id  : " << typeid(raw_data).name() << std::endl;
	std::cout << "type_id  : " << typeid(raw_ptr_data).name() << std::endl;
	std::cout << "type_id  : " << typeid(ret_data).name() << std::endl;
	std::cout << "type_id  : " << typeid(ret_data).name() << std::endl;

	return (0);
}
