/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:07:14 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/23 16:04:44 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(std::string name): name(name){};

Zombie::~Zombie()
{
	std::cout << this->name << " was destroyed" << std::endl;
};

std::string	Zombie::get_name() const
{
	return (name);
}

void	Zombie::set_name(const std::string &name)
{
	this->name = name;
}

void Zombie::announce(void)
{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
