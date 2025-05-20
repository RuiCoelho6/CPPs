/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:10:25 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/20 14:38:01 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string type): type(type){};

Weapon::~Weapon(){};

std::string	Weapon::getType() const
{
	return (this->type);
}

void	Weapon::setType(const std::string weaponType)
{
	this->type = weaponType;
}
