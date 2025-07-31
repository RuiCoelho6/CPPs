/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:06:38 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/31 11:02:53 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	// Animal test;
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

	/* std::cout << "\n----- Testing Animal Thoughts -----\n" << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		std::cout << animals[i]->getType() << " thoughts:" << std::endl;
		if (animals[i]->getType() == "Dog")
			static_cast<Dog*>(animals[i])->showIdeas();
		else if (animals[i]->getType() == "Cat")
			static_cast<Cat*>(animals[i])->showIdeas();
	} */

	std::cout << "\n----- Testing Deep Copy -----\n" << std::endl;
	Dog originalDog;
	Dog copyDog = originalDog;
	Dog assignedDog;
	assignedDog = originalDog;
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	delete j;
	delete i;

	std::cout << "\n----- Cleaning Up Array -----\n" << std::endl;
	for (int i = 0; i < arraySize; i++)
		delete animals[i];

	return (0);
}