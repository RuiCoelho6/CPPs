#include "AForm.hpp"
#include "Bureaucrat.hpp"

const int AForm::HIGHEST_GRADE = 1;
const int AForm::LOWEST_GRADE = 150;

AForm::AForm() : _name("Default_AForm"), _isSigned(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE)
{
	std::cout << "AForm default constructor called" << std::endl;
}

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "AForm parameterized constructor called" << std::endl;
	validate_grade(gradeToSign);
	validate_grade(gradeToExecute);
}

AForm::AForm(const AForm &other) 
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm	&AForm::operator=(const AForm &other)
{
	std::cout << "AForm assignment operator called" << std::endl;
	if (this != &other)
		_isSigned = other._isSigned;
	return (*this);
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;
}

const std::string	&AForm::get_name() const
{
	return (_name);
}

bool	AForm::get_is_signed() const
{
	return (_isSigned);
}

int	AForm::get_grade_to_sign() const
{
	return (_gradeToSign);
}

int	AForm::get_grade_to_execute() const
{
	return (_gradeToExecute);
}

void	AForm::be_signed(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.get_grade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void	AForm::execute(const Bureaucrat& executor) const
{
	if (!_isSigned)
		throw FormNotSignedException();
	if (executor.get_grade() > _gradeToExecute)
		throw GradeTooLowException();
	execute_action();
}

void	AForm::validate_grade(int grade) const
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("AForm grade is too high! (minimum grade is 1)");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("AForm grade is too low! (maximum grade is 150)");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

std::ostream	&operator<<(std::ostream &out, const AForm &form)
{
	out << "AForm " << form.get_name() << ", signed: " << (form.get_is_signed() ? "yes" : "no")
		<< ", grade to sign: " << form.get_grade_to_sign() 
		<< ", grade to execute: " << form.get_grade_to_execute();
	return (out);
}