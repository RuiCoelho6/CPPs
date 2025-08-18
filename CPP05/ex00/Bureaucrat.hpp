#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat
{
	private:
		const std::string	_name;
		int					_grade;

	public:
		// Orthodox Canonical Form
		Bureaucrat();
		Bureaucrat(const std::string& name, int grade);
		Bureaucrat(const Bureaucrat& other);
		Bureaucrat	&operator=(const Bureaucrat& other);
		~Bureaucrat();

		// Getters
		const std::string&	getName() const;
		int					getGrade() const;

		// Grade modification functions
		void	incrementGrade();
		void	decrementGrade();

		// Exception classes
		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};

	private:
		void	validateGrade(int grade) const;
		static const int HIGHEST_GRADE;
		static const int LOWEST_GRADE;
};

// Insertion operator overload
std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif