#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

void	test_intern_basic_functionality()
{
	std::cout << "=== Testing Intern Basic Functionality ===" << std::endl;
	try
	{
		Intern	someRandomIntern;
		AForm	*forms[3];

		// Test creating each type of form
		forms[0] = someRandomIntern.makeForm("shrubbery creation", "home");
		forms[1] = someRandomIntern.makeForm("robotomy request", "Bender");
		forms[2] = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");

		// Display the created forms
		for (int i = 0; i < 3; i++)
		{
			if (forms[i])
				std::cout << *forms[i] << std::endl;
		}

		// Test with a high-level bureaucrat
		Bureaucrat	boss("Boss", 1);
		std::cout << "\n--- Testing form operations ---" << std::endl;
		
		for (int i = 0; i < 3; i++)
		{
			if (forms[i])
			{
				boss.sign_form(*forms[i]);
				boss.execute_form(*forms[i]);
				std::cout << std::endl;
			}
		}

		for (int i = 0; i < 3; i++)
			delete forms[i];
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_intern_unknown_form()
{
	std::cout << "=== Testing Intern with Unknown Form ===" << std::endl;
	try
	{
		Intern	intern;
		AForm	*form;

		// Try to create a non-existent form
		form = intern.makeForm("coffee making", "office");

		// This should not be reached if exception is thrown
		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	
	try
	{
		Intern	intern;
		AForm	*form;

		// Try another non-existent form
		form = intern.makeForm("tax evasion", "corporation");

		if (form)
		{
			std::cout << *form << std::endl;
			delete form;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_intern_form_name_variations()
{
	std::cout << "=== Testing Form Name Case Sensitivity ===" << std::endl;
	try
	{
		Intern	intern;
		AForm	*form;

		(void)form;
		// Test case sensitivity - these should fail
		std::cout << "Testing 'Robotomy Request' (capital R):" << std::endl;
		form = intern.makeForm("Robotomy Request", "Android");
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}

	try
	{
		Intern	intern;
		AForm	*form;

		(void)form;
		std::cout << "Testing 'SHRUBBERY CREATION' (all caps):" << std::endl;
		form = intern.makeForm("SHRUBBERY CREATION", "garden");
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_intern_workflow_integration()
{
	std::cout << "=== Testing Intern Workflow Integration ===" << std::endl;
	try
	{
		Intern		intern;
		Bureaucrat	ceo("CEO", 1);
		Bureaucrat	manager("Manager", 50);
		Bureaucrat	employee("Employee", 140);
		// Create different forms for different bureaucrats
		AForm		*shrubberyForm = intern.makeForm("shrubbery creation", "office_garden");
		AForm		*robotomyForm = intern.makeForm("robotomy request", "Faulty_AI");
		AForm		*pardonForm = intern.makeForm("presidential pardon", "Tax_Evader");

		std::cout << "\n--- Employee handles shrubbery ---" << std::endl;
		employee.sign_form(*shrubberyForm);
		manager.execute_form(*shrubberyForm); // Employee can't execute, manager can

		std::cout << "\n--- Manager handles robotomy ---" << std::endl;
		manager.sign_form(*robotomyForm);
		ceo.execute_form(*robotomyForm); // Manager can't execute, CEO can

		std::cout << "\n--- CEO handles pardon ---" << std::endl;
		ceo.sign_form(*pardonForm);
		ceo.execute_form(*pardonForm); // CEO can do both

		delete shrubberyForm;
		delete robotomyForm;
		delete pardonForm;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_intern_copy_and_assignment()
{
	std::cout << "=== Testing Intern Copy and Assignment ===" << std::endl;
	try
	{
		Intern	originalIntern;
		// Test copy constructor
		Intern	copyIntern(originalIntern);
		// Test assignment operator
		Intern	assignedIntern;
		assignedIntern = originalIntern;
		
		// Test that all interns work the same way
		AForm* form1 = originalIntern.makeForm("robotomy request", "Original");
		AForm* form2 = copyIntern.makeForm("robotomy request", "Copy");
		AForm* form3 = assignedIntern.makeForm("robotomy request", "Assigned");
		
		std::cout << *form1 << std::endl;
		std::cout << *form2 << std::endl;
		std::cout << *form3 << std::endl;
		
		delete form1;
		delete form2;
		delete form3;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_example_from_subject()
{
	std::cout << "=== Testing Example from Subject ===" << std::endl;
	try
	{
		Intern someRandomIntern;
		AForm* rrf;
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
		
		if (rrf)
		{
			std::cout << "Successfully created: " << *rrf << std::endl;
			
			// Let's also test it works
			Bureaucrat testBureaucrat("Test", 1);
			testBureaucrat.sign_form(*rrf);
			testBureaucrat.execute_form(*rrf);
			
			delete rrf;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

// Previous test functions (keeping a few key ones)
void	test_all_forms_complete_workflow()
{
	std::cout << "=== Testing Complete Workflow for All Forms ===" << std::endl;
	try
	{
		Intern intern;

		// Create forms using intern
		AForm* shrubbery = intern.makeForm("shrubbery creation", "office");
		AForm* robotomy = intern.makeForm("robotomy request", "Employee");
		AForm* pardon = intern.makeForm("presidential pardon", "Citizen");
		// Create bureaucrats
		Bureaucrat ceo("CEO", 1);
		Bureaucrat manager("Manager", 50);
		Bureaucrat employee("Employee", 140);

		std::cout << "\n--- Forms ---" << std::endl;
		std::cout << *shrubbery << std::endl;
		std::cout << *robotomy << std::endl;
		std::cout << *pardon << std::endl;

		std::cout << "\n--- Signing Phase ---" << std::endl;
		employee.sign_form(*shrubbery);	// Grade 140 can sign (needs 145)
		manager.sign_form(*robotomy);	// Grade 50 can sign (needs 72)
		ceo.sign_form(*pardon);			// Grade 1 can sign (needs 25)

		std::cout << "\n--- Execution Phase ---" << std::endl;
		manager.execute_form(*shrubbery);	// Grade 50 can execute (needs 137)
		ceo.execute_form(*robotomy);		// Grade 1 can execute (needs 45)
		ceo.execute_form(*pardon);			// Grade 1 can execute (needs 5)

		delete shrubbery;
		delete robotomy;
		delete pardon;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main()
{
	test_example_from_subject();
	test_intern_basic_functionality();
	test_intern_unknown_form();
	test_intern_form_name_variations();
	test_intern_workflow_integration();
	test_intern_copy_and_assignment();
	test_all_forms_complete_workflow();

	return (0);
}