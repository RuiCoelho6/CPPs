/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:40:58 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/23 19:28:01 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <string>

std::string	replaceAll(const std::string& line, const std::string& s1, const std::string& s2)
{
	std::string	result;
	size_t	i = 0;
	size_t	pos;

	while (i < line.length())
	{
		pos = line.find(s1, i);
		if (pos == std::string::npos)
		{
			result += line.substr(i);
			break ;
		}
		result += line.substr(i, pos - i);
		result += s2;
		i = pos + s1.length();
	}
	return (result);
}

int	main(int argc, char** argv)
{
	if (argc != 4)
	{
		std::cout << "Usage: " << argv[0] << " <filename> <s1> <s2>\n";
		return (1);
	}

	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];

	if (s1.empty())
	{
		std::cout << "Error: s1 cannot be empty.\n";
		return (1);
	}

	std::ifstream input(filename.c_str());
	if (!input)
	{
		std::cout << "Error: Cannot open file " << filename << "\n";
		return (1);
	}

	std::ofstream output((filename + ".replace").c_str());
	if (!output)
	{
		std::cout << "Error: Cannot create output file.\n";
		return (1);
	}

	std::string line;
	while (std::getline(input, line))
		output << replaceAll(line, s1, s2) << "\n";

	input.close();
	output.close();
	return (0);
}
