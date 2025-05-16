/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:06:44 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/16 15:10:48 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <iostream>

class Zombie
{
	private:
		std::string name;
		
	public:
		Zombie(std::string name="");
		~Zombie();

		void	announce(void);

		void	set_name(const std::string &name);
		std::string	get_name(void) const;
};

Zombie	*newZombie(std::string name);
void	randomChump( std::string name);

#endif
