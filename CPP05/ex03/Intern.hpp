#ifndef INTERN_HPP
#define INTERN_HPP

#include <string>
#include <iostream>
#include "AForm.hpp"

class Intern
{
	private:
		struct FormCreator
		{
			std::string	formName;
			AForm	*(*createFunction)(const std::string &target);
		};

		static const FormCreator	_formCreators[3];
		static const int			_numForms;

		static AForm	*createShrubberyForm(const std::string &target);
		static AForm	*createRobotomyForm(const std::string &target);
		static AForm	*createPresidentialForm(const std::string &target);

	public:
		Intern();
		Intern(const Intern &other);
		Intern	&operator=(const Intern &other);
		~Intern();

		AForm	*makeForm(const std::string &formName, const std::string &target);

		// Exception for unknown form names
		class UnknownFormException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

#endif