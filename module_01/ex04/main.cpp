/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyoulee <kyoulee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 11:46:48 by kyoulee           #+#    #+#             */
/*   Updated: 2022/12/02 18:18:48 by kyoulee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string	ft_file_replace(char *argv[], std::string file_contents)
{
	std::string	file_replace;
	int			index;
	int			find_index;
	int			replace_len;
	
	index = 0;
	find_index = 0;
	file_replace.clear();
	replace_len = std::string(argv[2]).length();
	while (1)
	{
		find_index = file_contents.find(argv[2], index);
		if (find_index == (int)std::string::npos)
			break ;
		file_replace.append(file_contents, index, find_index - index);
		index = find_index + replace_len;
		file_replace.append(argv[3]);
	}
	file_replace.append(file_contents, index);
	return (file_replace);
}

int	main(int argc, char *argv[])
{
	std::ifstream	file_in;
	std::ofstream	file_out;
	std::string		file_contents;

	if (argc != 4 || !*argv[1] || !*argv[2])
	{
		std::cout << "argv[4] : 'cmd' 'file_name' 'target_str' 'chang_str'" << std::endl;
		std::cout << "Error : argument " << std::endl;
		return (1);
	}
	file_in.open(argv[1]);
	if (!file_in || !(file_in.is_open()))
	{
		std::cout << "Error : in file " << std::endl;
		file_in.close();
		return (2);
	}
	file_out.open((std::string)argv[1] + ".replace");
	if (!file_out || !(file_out.is_open()))
	{
		std::cout << "Error : out file " << std::endl;
		(file_in.close(), file_out.close());
		return (2);
	}
	file_contents.resize(file_in.seekg(0, file_in.end).tellg());
	file_in.seekg(0, file_in.beg);
	file_in.read(&file_contents[0], file_contents.size());
	file_out << ft_file_replace(argv, file_contents);
	file_out.close();
	file_in.close();
	return (0);
}
