/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:34:55 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/01 14:46:20 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

//Constructor
Contact::Contact() : first_name(""), last_name(""), nickname(""), phone_number(""), darkest_secret("") {}

//Destructor
Contact::~Contact()
{
	std::cout << "Contact destroyed" << std::endl;
}

//Setters
void	Contact::set_first_name(const std::string &first_name)
{
	this->first_name = first_name;
}

void	Contact::set_last_name(const std::string &last_name)
{
	this->last_name = last_name;
}

void	Contact::set_nickname(const std::string &nickname)
{
	this->nickname = nickname;
}

void	Contact::set_phone_number(const std::string &phone_number)
{
	this->phone_number = phone_number;
}

void	Contact::set_darkest_secret(const std::string &darkest_secret)
{
	this->darkest_secret = darkest_secret;
}

//Getters
std::string	Contact::get_first_name() const
{
	return first_name;
}

std::string	Contact::get_last_name() const
{
	return last_name;
}

std::string	Contact::get_nickname() const
{
	return nickname;
}

std::string	Contact::get_phone_number() const
{
	return phone_number;
}

std::string	Contact::get_darkest_secret() const
{
	return darkest_secret;
}
