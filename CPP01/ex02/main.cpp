/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpires-c <rpires-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 16:07:52 by rpires-c          #+#    #+#             */
/*   Updated: 2025/05/16 16:39:14 by rpires-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";

	std::string* str_ptr = &str;
	std::string& str_ref = str;

	std::cout << "Address of the string variable: " << &str << std::endl;
	std::cout << "Address held by string_ptr: " << str_ptr << std::endl;
	std::cout << "Address held by string_ref: " << &str_ref << std::endl;

	std::cout << std::endl << "Original string variable: " << str << std::endl;
	std::cout << "Value pointed to by string_ptr: " << *str_ptr << std::endl;
	std::cout << "Value pointed to by string_ref: " << str_ref << std::endl;

	return 0;
}