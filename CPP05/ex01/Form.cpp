#include "Form.hpp"
#include "Bureaucrat.hpp"

const int Form::HIGHEST_GRADE = 1;
const int Form::LOWEST_GRADE = 150;

Form::Form() : _name("Default_Form"), _isSigned(false), _gradeToSign(LOWEST_GRADE), _gradeToExecute(LOWEST_GRADE)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const std::string& name, int gradeToSign, int gradeToExecute) 
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	std::cout << "Form parameterized constructor called" << std::endl;
	validateGrade(gradeToSign);
	validateGrade(gradeToExecute);
}

Form::Form(const Form& other) 
	: _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form	&Form::operator=(const Form& other)
{
	std::cout << "Form assignment operator called" << std::endl;
	if (this != &other)
	{
		// Only _isSigned can be changed, as other members are const
		_isSigned = other._isSigned;
	}
	return (*this);
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}

const std::string	&Form::getName() const
{
	return (_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
		throw GradeTooLowException();
	_isSigned = true;
}

void	Form::validateGrade(int grade) const
{
	if (grade < HIGHEST_GRADE)
		throw GradeTooHighException();
	if (grade > LOWEST_GRADE)
		throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Form grade is too high! (minimum grade is 1)");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Form grade is too low! (maximum grade is 150)");
}

std::ostream	&operator<<(std::ostream& out, const Form& form)
{
	out << "Form " << form.getName() << ", signed: " << (form.getIsSigned() ? "yes" : "no")
		<< ", grade to sign: " << form.getGradeToSign() 
		<< ", grade to execute: " << form.getGradeToExecute();
	return (out);
}