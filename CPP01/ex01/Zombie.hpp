/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:33:23 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/16 15:33:25 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <string>
# include <sstream>
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

Zombie	*zombieHorde(int N, std::string name);

#endif