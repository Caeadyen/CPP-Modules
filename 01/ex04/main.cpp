/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 10:42:19 by hrings            #+#    #+#             */
/*   Updated: 2022/09/15 15:24:27 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_replace.hpp"


int	main(int argc, char **argv)
{

	std::string file_content;
	std::string output;
	std::stringstream strStream;
	std::ifstream file_input;
	std::ofstream file_output;

	if (argc != 4)
	{
		std::cout << "Wrong Number of Arguments" << std::endl;
		std::cout << "need: filename string string" << std::endl;
		return (1);
	}
	if (!openFiles(file_input, file_output, argv[1]))
		return (1);
	ft_replace(file_input, file_output, argv[2], argv[3]);
	file_input.close();
	file_output.close();
	return 0;
}

bool openFiles(std::ifstream &input, std::ofstream &output, std::string filename)
{
	input.open(filename.c_str());
	if (!input.is_open())
	{
		std::cout << "Failed to open input file" << std::endl;
		return (false);
	}
	output.open((filename + ".replace").c_str());
	if (!output.is_open())
	{
		std::cout << "Failed to open output file" << std::endl;
		input.close();
		return (false);
	}
	return (true);
}

void ft_replace(std::ifstream &input, std::ofstream &output, char *oldword, char *newword)
{
	const std::string::size_type old_len = strlen(oldword);
	std::string::size_type index;
	std::string line;

	while (std::getline(input, line))
	{
		index = line.find(oldword);
		while (index != std::string::npos)
		{			
			index = line.find(oldword, index);
			line.erase(index, old_len);
			line.insert(index, newword);
			index += strlen(newword);
			index = line.find(oldword, index);
		}
		output << line;
		if (input.good()) 
			output << std::endl;
	}
}
