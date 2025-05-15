/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 16:38:30 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/01 15:29:56 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"

Phonebook::Phonebook() : number_of_contacts(0), oldest_contact(0){}

Phonebook::~Phonebook()
{
	std::cout << "Phonebook destroyed" << std::endl;
}

void	Phonebook::add_contact(const Contact &contact)
{
	if(number_of_contacts < 8)
	{
		contacts[number_of_contacts] = contact;
		number_of_contacts++;
	}
	else
	{
		contacts[oldest_contact] = contact;
		oldest_contact = (oldest_contact + 1) % 8;
	}
}

void	Phonebook::format_field(const std::string &field) const
{
	if (field.length() <= 10)
		std::cout << std::setw(10) << field;
	else
		std::cout << field.substr(0, 9) << field << ".";
}

void	Phonebook::search_contact() const
{
	if (number_of_contacts == 0)
	{
		std::cout << "Contact list is empty!" << std::endl;
		return ;
	}

	std::cout << "|" << std::setw(10) << "Index" << "|";
	std::cout << std::setw(10) << "First name" << "|";
	std::cout << std::setw(10) << "Last name" << "|";
	std::cout << std::setw(10) << "Nickname" << "|" << std::endl;

	for(int i = 0; i < number_of_contacts; i++)
	{
		std::cout << "|" << std::setw(10) << i << "|";
		format_field(contacts[i].get_first_name());
		std::cout << "|";
		format_field(contacts[i].get_last_name());
		std::cout << "|";
		format_field(contacts[i].get_nickname());
		std::cout << "|" << std::endl;
	}
}

void	Phonebook::display_contact_info(int index) const
{
	if (index < 0 || index >= number_of_contacts)
	{
		std::cout << "Index out of bounds" << std::endl;
		return ;
	}

	std::cout << "Index: " << index << std::endl;
	std::cout << "First name: " << contacts[index].get_first_name() << std::endl;
	std::cout << "Last name: " << contacts[index].get_last_name() << std::endl;
	std::cout << "Nickname: " << contacts[index].get_nickname() << std::endl;
	std::cout << "Phone number: " << contacts[index].get_phone_number() << std::endl;
	std::cout << "Darkest secret: " << contacts[index].get_darkest_secret() << std::endl;
}
