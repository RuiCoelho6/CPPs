#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

// Initialize static members
const int Intern::_numForms = 3;

const Intern::FormCreator	Intern::_formCreators[3] =
{
	{"shrubbery creation", &Intern::createShrubberyForm},
	{"robotomy request", &Intern::createRobotomyForm},
	{"presidential pardon", &Intern::createPresidentialForm}
};

Intern::Intern()
{
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	std::cout << "Intern copy constructor called" << std::endl;
	(void)other;
}

Intern	&Intern::operator=(const Intern &other)
{
	std::cout << "Intern assignment operator called" << std::endl;
	(void)other;
	return (*this);
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm	*Intern::makeForm(const std::string &formName, const std::string &target)
{
	for (int i = 0; i < _numForms; i++)
	{
		if (_formCreators[i].formName == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return (_formCreators[i].createFunction(target));
		}
	}

	std::cout << "Intern cannot create form: " << formName << " (unknown form type)" << std::endl;
	throw UnknownFormException();
}

AForm	*Intern::createShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm	*Intern::createRobotomyForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm	*Intern::createPresidentialForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

const char	*Intern::UnknownFormException::what() const throw()
{
	return ("Unknown form type requested");
}