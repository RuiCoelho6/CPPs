#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat; // Forward declaration

class Form
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
		static const int	HIGHEST_GRADE;
		static const int	LOWEST_GRADE;
		void	validate_grade(int grade) const;

	public:
		Form();
		Form(const std::string &name, int gradeToSign, int gradeToExecute);
		Form(const Form &other);
		Form	&operator=(const Form &other);
		~Form();

		const std::string&	get_name() const;
		bool				get_is_signed() const;
		int					get_grade_to_sign() const;
		int					get_grade_to_execute() const;

		void	be_signed(const Bureaucrat& bureaucrat);

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
};

std::ostream	&operator<<(std::ostream &out, const Form &form);

#endif