/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 12:07:56 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/23 16:08:18 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	std::cout << "Creating a stack zombie:" << std::endl;
	Zombie stackZombie("Stack Zombie");
	stackZombie.announce();

	std::cout << "\nCreating a heap zombie:" << std::endl;
	Zombie* heapZombie = newZombie("Heap Zombie");
	heapZombie->announce();
	delete heapZombie;

	std::cout << "\nCalling randomChump:" << std::endl;
	randomChump("Random Zombie");

	std::cout << "\nEnd of function, stack zombies will be destroyed automatically" << std::endl;
	return (0);
}