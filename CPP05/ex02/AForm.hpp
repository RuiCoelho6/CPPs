#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include <iostream>
#include <exception>

class Bureaucrat; // Forward declaration

class AForm
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
		AForm();
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm(const AForm& other);
		AForm	&operator=(const AForm& other);
		virtual ~AForm();

		const std::string&	get_name() const;
		bool				get_is_signed() const;
		int					get_grade_to_sign() const;
		int					get_grade_to_execute() const;

		void	be_signed(const Bureaucrat& bureaucrat);
		void	execute(const Bureaucrat& executor) const;

		// Pure virtual function to make this class abstract
		virtual void	execute_action() const = 0;

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
		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char	*what() const throw();
		};
};

std::ostream	&operator<<(std::ostream& out, const AForm& form);

#endif