/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:29:39 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/29 19:06:11 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(): Animal()
{
	this->type = "Cat";
	brain = new Brain();
	std::cout << "Cat default constructor called" << std::endl;
}
Cat::Cat(const Cat &other) : Animal(other)
{
	this->brain = new Brain(*other.brain);
	std::cout << "Cat copy constructor called" << std::endl;
}

Cat	&Cat::operator=(const Cat &other)
{
	if (this != &other)
	{
		delete brain;
		brain = new Brain(*other.brain);
		Animal::operator=(other);
		std::cout << "Cat assignment operator called" << std::endl;
	}
	return *this;
}

Cat::~Cat()
{
	delete brain;
	std::cout << "Cat destructor called" << std::endl;
}

void	Cat::makeSound() const
{
	std::cout << "Meow! Meow!" << std::endl;
}
