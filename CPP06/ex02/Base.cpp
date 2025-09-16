/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:57:44 by rpires-c          #+#    #+#             */
/*   Updated: 2025/09/16 14:57:45 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

Base::~Base()
{
	std::cout << "Base destructor" << std::endl;
}

Base*	generate(void)
{
	static bool	seeded = false;
	if (!seeded)
	{
		std::srand(std::time(0));
		seeded = true;
	}

	int	random = std::rand() % 3;
	switch (random)
	{
		case 0:
			std::cout << "Generated: A" << std::endl;
			return (new A());
		case 1:
			std::cout << "Generated: B" << std::endl;
			return (new B());
		case 2:
			std::cout << "Generated: C" << std::endl;
			return (new C());
		default:
			return (new A());
	}
}

void	identify(Base* p)
{
	if (!p)
	{
		std::cout << "Null pointer!" << std::endl;
		return ;
	}

	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown type" << std::endl;
}

// dynamic_cast with references throws std::bad_cast if it fails
void	identify(Base& p)
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		(void)a;
		std::cout << "A" << std::endl;
		return ;
	}
	catch (const std::exception	&e)
	{
		// Continue if not an A
	}

	try
	{
		B	&b = dynamic_cast<B&>(p);
		(void)b;
		std::cout << "B" << std::endl;
		return ;
	}
	catch (const std::exception& e)
	{
		// Continue if not a B
	}

	try
	{
		C	&c = dynamic_cast<C&>(p);
		(void)c;
		std::cout << "C" << std::endl;
		return ;
	}
	catch (const std::exception& e)
	{
		// Not a C
		std::cout << "Unknown type" << std::endl;
	}
}