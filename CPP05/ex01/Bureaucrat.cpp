#include "Bureaucrat.hpp"
#include "Form.hpp"

const int	Bureaucrat::HIGHEST_GRADE = 1;
const int	Bureaucrat::LOWEST_GRADE = 150;

Bureaucrat::Bureaucrat() : _name("Default_Bureaucrat"), _grade(LOWEST_GRADE)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name), _grade(grade)
{
	std::cout << "Bureaucrat parameterized constructor called with grade: " << grade << std::endl;
	validate_grade(grade);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	std::cout << "Bureaucrat assignment operator called" << std::endl;
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}

const std::string	&Bureaucrat::get_name() const
{
	return (_name);
}

int	Bureaucrat::get_grade() const
{
	return (_grade);
}

void	Bureaucrat::increment_grade()
{
	validate_grade(_grade - 1);
	_grade--;
}

void	Bureaucrat::decrement_grade()
{
	validate_grade(_grade + 1);
	_grade++;
}

void	Bureaucrat::sign_form(Form& form)
{
	try
	{
		form.be_signed(*this);
		std::cout << _name << " signed " << form.get_name() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << _name << " couldn't sign " << form.get_name() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::validate_grade(int grade) const
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high! (minimum grade is 1)");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low! (maximum grade is 150)");
}

std::ostream	&operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.get_name() << ", bureaucrat grade " << bureaucrat.get_grade();
	return (out);
}