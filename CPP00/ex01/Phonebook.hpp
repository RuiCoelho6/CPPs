/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 11:48:23 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/01 14:46:42 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iomanip>

class Phonebook
{
	private:
		Contact	contacts[8];
		int		number_of_contacts;
		int		oldest_contact;

		void format_field(const std::string &field) const;

	public:
		Phonebook();
		~Phonebook();

		void	add_contact(const Contact &contact);
		void	search_contact() const;
		void	display_contact_info(int index) const;
};

#endif