/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hrings <hrings@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 17:12:50 by hrings            #+#    #+#             */
/*   Updated: 2022/09/15 15:15:43 by hrings           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REPLACE_HPP
# define FT_REPLACE_HPP

# include <iostream>
# include <fstream>
# include <string>
#include <sstream>
#include <cstring>

void ft_replace(std::ifstream &input, std::ofstream &output, char *oldword, char *newword);
bool openFiles(std::ifstream &input, std::ofstream &output, std::string filename);

#endif