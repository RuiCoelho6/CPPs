/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 14:57:49 by rpires-c          #+#    #+#             */
/*   Updated: 2025/09/16 14:57:50 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

int main(void)
{
	std::cout << "=== Testing Type Identification ===" << std::endl;
	std::cout << std::endl;
	
	// Test multiple random generations
	std::cout << "--- Testing generate() and identify() functions ---" << std::endl;
	for (int i = 0; i < 10; i++)
	{
		std::cout << "Test " << (i + 1) << ": ";
		Base	*obj = generate();
		
		std::cout << "Identify by pointer: ";
		identify(obj);
		
		std::cout << "Identify by reference: ";
		identify(*obj);
		
		delete obj;
		std::cout << std::endl;
	}
	
	std::cout << "--- Testing edge cases ---" << std::endl;
	
	// Test with null pointer
	std::cout << "Testing null pointer: ";
	identify(static_cast<Base*>(0));
	
	// Test with direct instantiation
	std::cout << "Testing direct A instantiation:" << std::endl;
	A	*a = new A();
	std::cout << "Pointer identification: ";
	identify(a);
	std::cout << "Reference identification: ";
	identify(*a);
	delete a;
	
	std::cout << std::endl;
	std::cout << "Testing direct B instantiation:" << std::endl;
	B	*b = new B();
	std::cout << "Pointer identification: ";
	identify(b);
	std::cout << "Reference identification: ";
	identify(*b);
	delete b;
	
	std::cout << std::endl;
	std::cout << "Testing direct C instantiation:" << std::endl;
	C	*c = new C();
	std::cout << "Pointer identification: ";
	identify(c);
	std::cout << "Reference identification: ";
	identify(*c);
	delete c;
	
	std::cout << std::endl;
	std::cout << "=== All tests completed ===" << std::endl;
	
	return (0);
}