/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 15:44:08 by hrings            #+#    #+#             */
/*   Updated: 2022/09/14 13:36:38 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

static void	print_string_upper(char *line);

int main(int argc, char **argv)
{
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		for (int i = 1; i < argc; i++)
		{
			print_string_upper(argv[i]);
			if (i != argc - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return (0);
}

static void	print_string_upper(char *line)
{
	int	strlen;
	std::string	str(line);

	strlen = str.length();
	for (int i = 0; i < strlen; i++)
		std::cout << (char)std::toupper(str[i]);
	 
}
