#include "Bureaucrat.hpp"

const int Bureaucrat::HIGHEST_GRADE = 1;
const int Bureaucrat::LOWEST_GRADE = 150;

// Default constructor
Bureaucrat::Bureaucrat() : _name("Default"), _grade(LOWEST_GRADE)
{
}

// Parameterized constructor
Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(grade)
{
	validateGrade(grade);
}

// Copy constructor
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

// Assignment operator
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

// Destructor
Bureaucrat::~Bureaucrat()
{
}

// Getters
const std::string	&Bureaucrat::getName() const
{
	return (_name);
}

int	Bureaucrat::getGrade() const
{
	return (_grade);
}

// Grade modification functions
void	Bureaucrat::incrementGrade()
{
	validateGrade(_grade - 1);
	_grade--;
}

void	Bureaucrat::decrementGrade()
{
	validateGrade(_grade + 1);
	_grade++;
}

// Private validation function
void	Bureaucrat::validateGrade(int grade) const
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

// Exception class implementations
const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high! (minimum grade is 1)");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low! (maximum grade is 150)");
}

// Insertion operator overload
std::ostream	&operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return (out);
}