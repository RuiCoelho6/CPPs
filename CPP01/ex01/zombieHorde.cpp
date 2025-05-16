/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 15:10:05 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/16 15:50:22 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	Zombie	*horde = new Zombie[N];

	for (int i = 1; i <= N; i++)
	{
		std::ostringstream oss;
		oss << name << i;
		horde[i - 1].set_name(oss.str());
		horde[i - 1].announce();
	}

	return (horde);
}
