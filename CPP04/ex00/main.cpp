/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 15:06:38 by rpires-c          #+#    #+#             */
/*   Updated: 2025/07/29 19:09:14 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int	main()
{
	std::cout << "\n----- Testing Animal and Dog/Cat Constructors -----\n" << std::endl;

	std::cout << "Default constructors:" << std::endl;
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << "\nCopy constructors:" << std::endl;
	Dog dog1;
	Dog dog2(dog1);
	Cat cat1;
	Cat cat2(cat1);

	std::cout << "\nAssignment operators:" << std::endl;
	Dog dog3;
	dog3 = dog1;
	Cat cat3;
	cat3 = cat1;

	std::cout << "\nTesting functionality:" << std::endl;
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound();
	j->makeSound();
	meta->makeSound();

	std::cout << "\n----- Testing WrongAnimal and WrongCat Constructors -----\n" << std::endl;

	std::cout << "Default constructors:" << std::endl;
	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_cat = new WrongCat();

	std::cout << "\nCopy constructors:" << std::endl;
	WrongCat wcat1;
	WrongCat wcat2(wcat1);

	std::cout << "\nAssignment operators:" << std::endl;
	WrongCat wcat3;
	wcat3 = wcat1;

	std::cout << "\nTesting functionality:" << std::endl;
	std::cout << wrong_meta->getType() << " " << std::endl;
	std::cout << wrong_cat->getType() << " " << std::endl;
	wrong_meta->makeSound();
	wrong_cat->makeSound();

	std::cout << "\n----- Cleaning up -----\n" << std::endl;
	delete meta;
	delete j;
	delete i;
	delete wrong_meta;
	delete wrong_cat;

	return (0);
}