/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:09:09 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/23 16:13:27 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	int	N = 3;

	std::cout << "Creating a stack zombie:" << std::endl;
	Zombie stackZombie("Stack Zombie");
	stackZombie.announce();

	std::cout << "\nCreating a zombie array:" << std::endl;
	Zombie *horde = zombieHorde(N, "bob ");
	std::cout << "Destroying the zombie array:" << std::endl;
	delete []horde;
	std::cout << "\nEnd of function, stack zombies will be destroyed automatically" << std::endl;
	return (0);
}
