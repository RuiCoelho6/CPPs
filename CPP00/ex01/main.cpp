/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 13:32:12 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/01 15:43:43 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <algorithm>
#include <cctype>
#include <sstream>

Contact	create_contact()
{
	Contact		contact;
	std::string	input;

	do
	{
		std::cout << "Enter first name: ";
		std::cin >> input;
		if (input.empty())
			std::cout << "This field can't be empty!" << std::endl;
	} while (input.empty());
	contact.set_first_name(input);
	do
	{
		std::cout << "Enter last name: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "This field can't be empty!" << std::endl;
	} while (input.empty());
	contact.set_last_name(input);
	do
	{
		std::cout << "Enter nickname: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "This field can't be empty!" << std::endl;
	} while (input.empty());
	contact.set_nickname(input);
	do
	{
		std::cout << "Enter phone number: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "This field can't be empty!" << std::endl;
	} while (input.empty());
	contact.set_phone_number(input);
	do
	{
		std::cout << "Enter darkest secret: ";
		std::getline(std::cin, input);
		if (input.empty())
			std::cout << "This field can't be empty!" << std::endl;
	} while (input.empty());
	contact.set_darkest_secret(input);
	return (contact);
}

int	main(void)
{
	std::string	operation;
	Phonebook	phonebook;

	while (true)
	{
		std::cout << "Enter operation (ADD, SEARCH or EXIT): ";
		std::cin >> operation;
		std::transform(operation.begin(), operation.end(), operation.begin(), ::tolower);

		if (operation == "add")
			{
				Contact contact = create_contact();

				phonebook.add_contact(contact);
				std::cout << "Contact added successfuly!" << std::endl;
			}
		else if (operation == "search")
			{
				std::string	input;

				phonebook.search_contact();
				std::cout << "Enter index: ";
				std::cin >> input;
				try
				{
					int index = 0;

					std::stringstream ss(input);
					if (!(ss >> index))
						std::cout << "Invalid phone number!" << std::endl;
					else
						phonebook.display_contact_info(index);
				}
				catch (const std::exception &e)
				{
					std::cout << "Invalid index!" << std::endl;
				}
			}
		else if (operation == "exit")
			{
				std::cout << "Goodbye!" << std::endl;
				break ;
			}
	}
	return (0);
}
