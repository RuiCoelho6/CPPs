/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:06:38 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/29 19:08:26 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << "\n----- Creating Animal Array -----\n" << std::endl;
	const int arraySize = 4;
	Animal* animals[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		if (i < arraySize / 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << "\n----- Testing Deep Copy -----\n" << std::endl;
	Dog originalDog;
	Dog copyDog = originalDog;
	Dog assignedDog;
	assignedDog = originalDog;

	std::cout << "\n----- Cleaning Up Array -----\n" << std::endl;
	for (int i = 0; i < arraySize; i++)
		delete animals[i];

	return (0);
}