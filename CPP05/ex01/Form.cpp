#include "Form.hpp"
#include "Bureaucrat.hpp"

const int Form::HIGHEST_GRADE = 1;
const int Form::LOWEST_GRADE = 150;

Form::Form() : _name("Default_Form"), _isSigned(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string &name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form parameterized constructor called" << std::endl;
	validate_grade(gradeToSign);
	validate_grade(gradeToExecute);
}

Form::Form(const Form &other) 
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form	&Form::operator=(const Form &other)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string	&Form::get_name() const
{
	return (_name);
}

bool	Form::get_is_signed() const
{
	return (_isSigned);
}

int	Form::get_grade_to_sign() const
{
	return (_gradeToSign);
}

int	Form::get_grade_to_execute() const
{
	return (_gradeToExecute);
}

void	Form::be_signed(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.get_grade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void	Form::validate_grade(int grade) const
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high! (minimum grade is 1)");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low! (maximum grade is 150)");
}

std::ostream	&operator<<(std::ostream &out, const Form &form)
{
	out << "Form " << form.get_name() << ", signed: " << (form.get_is_signed() ? "yes" : "no")
		<< ", grade to sign: " << form.get_grade_to_sign() 
		<< ", grade to execute: " << form.get_grade_to_execute();
	return (out);
}