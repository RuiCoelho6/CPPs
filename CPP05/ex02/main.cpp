#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test_shrubbery_creation()
{
	std::cout << "=== Testing Shrubbery Creation Form ===" << std::endl;
	try
	{
		ShrubberyCreationForm	shrubbery("home");
		std::cout << shrubbery << std::endl;
		
		Bureaucrat	gardener("Gardener", 140);
		std::cout << gardener << std::endl;
		
		// Sign the form
		gardener.sign_form(shrubbery);
		std::cout << "After signing: " << shrubbery << std::endl;
		
		// Execute the form
		gardener.execute_form(shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_robotomy_request()
{
	std::cout << "=== Testing Robotomy Request Form ===" << std::endl;
	try
	{
		RobotomyRequestForm	robotomy("Bender");
		std::cout << robotomy << std::endl;
		
		Bureaucrat	surgeon("Dr. Robot", 40);
		std::cout << surgeon << std::endl;
		
		// Sign and execute
		surgeon.sign_form(robotomy);
		surgeon.execute_form(robotomy);
		
		// Try multiple executions to see the 50% chance
		std::cout << "\n--- Multiple execution attempts ---" << std::endl;
		for (int i = 0; i < 5; i++)
		{
			std::cout << "Attempt " << (i + 1) << ": ";
			surgeon.execute_form(robotomy);
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_presidential_pardon()
{
	std::cout << "=== Testing Presidential Pardon Form ===" << std::endl;
	try
	{
		PresidentialPardonForm	pardon("Arthur Dent");
		std::cout << pardon << std::endl;
		
		Bureaucrat	president("Zaphod", 1);
		std::cout << president << std::endl;
		
		// Sign and execute
		president.sign_form(pardon);
		president.execute_form(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_insufficient_grade_to_sign()
{
	std::cout << "=== Testing Insufficient Grade to Sign ===" << std::endl;
	try
	{
		PresidentialPardonForm	pardon("Criminal");
		Bureaucrat	lowLevel("Intern", 100);
		
		std::cout << lowLevel << std::endl;
		std::cout << pardon << std::endl;
		
		// Try to sign with insufficient grade
		lowLevel.sign_form(pardon);
		
		// Try to execute unsigned form
		lowLevel.execute_form(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_insufficient_grade_to_execute()
{
	std::cout << "=== Testing Insufficient Grade to Execute ===" << std::endl;
	try
	{
		RobotomyRequestForm	robotomy("Patient");
		Bureaucrat	signer("Boss", 50);
		Bureaucrat	executor("Nurse", 80);
		
		std::cout << signer << std::endl;
		std::cout << executor << std::endl;
		std::cout << robotomy << std::endl;
		
		// Sign with sufficient grade
		signer.sign_form(robotomy);
		
		// Try to execute with insufficient grade
		executor.execute_form(robotomy);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_execution_without_signing()
{
	std::cout << "=== Testing Execution Without Signing ===" << std::endl;
	try
	{
		ShrubberyCreationForm	shrubbery("garden");
		Bureaucrat	admin("Admin", 1);
		
		std::cout << admin << std::endl;
		std::cout << shrubbery << std::endl;
		
		// Try to execute unsigned form (even with highest grade)
		admin.execute_form(shrubbery);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_all_forms_complete_workflow()
{
	std::cout << "=== Testing Complete Workflow for All Forms ===" << std::endl;
	try
	{
		// Create forms
		ShrubberyCreationForm	shrubbery("office");
		RobotomyRequestForm	robotomy("Employee");
		PresidentialPardonForm	pardon("Citizen");
		
		// Create bureaucrats
		Bureaucrat	ceo("CEO", 1);
		Bureaucrat	manager("Manager", 50);
		Bureaucrat	employee("Employee", 140);
		
		std::cout << "--- Forms ---" << std::endl;
		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pardon << std::endl;
		
		std::cout << "\n--- Bureaucrats ---" << std::endl;
		std::cout << ceo << std::endl;
		std::cout << manager << std::endl;
		std::cout << employee << std::endl;
		
		std::cout << "\n--- Signing Phase ---" << std::endl;
		employee.sign_form(shrubbery);	// Grade 140 can sign (needs 145)
		manager.sign_form(robotomy);	// Grade 50 can sign (needs 72)
		ceo.sign_form(pardon);			// Grade 1 can sign (needs 25)
		
		std::cout << "\n--- Execution Phase ---" << std::endl;
		employee.execute_form(shrubbery);	// Grade 140 cannot execute (needs 137)
		manager.execute_form(shrubbery);	// Grade 50 can execute (needs 137)
		
		manager.execute_form(robotomy);		// Grade 50 cannot execute (needs 45)
		ceo.execute_form(robotomy);			// Grade 1 can execute (needs 45)
		
		ceo.execute_form(pardon);			// Grade 1 can execute (needs 5)
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_form_inheritance_and_polymorphism()
{
	std::cout << "=== Testing Polymorphism ===" << std::endl;
	try
	{
		// Test polymorphism with AForm pointers
		AForm	*forms[3];
		forms[0] = new ShrubberyCreationForm("park");
		forms[1] = new RobotomyRequestForm("Android");
		forms[2] = new PresidentialPardonForm("Rebel");
		
		Bureaucrat	superBoss("SuperBoss", 1);
		
		for (int i = 0; i < 3; i++)
		{
			std::cout << *forms[i] << std::endl;
			superBoss.sign_form(*forms[i]);
			superBoss.execute_form(*forms[i]);
			std::cout << std::endl;
		}
		
		// Clean up
		for (int i = 0; i < 3; i++)
			delete forms[i];
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_copy_and_assignment()
{
	std::cout << "=== Testing Copy Constructor and Assignment ===" << std::endl;
	try
	{
		ShrubberyCreationForm	original("original_target");
		Bureaucrat	signer("Signer", 100);
		
		std::cout << "Original: " << original << std::endl;
		signer.sign_form(original);
		std::cout << "Original after signing: " << original << std::endl;
		
		// Test copy constructor
		ShrubberyCreationForm	copy(original);
		std::cout << "Copy: " << copy << std::endl;
		
		// Test assignment operator
		ShrubberyCreationForm	assigned("temp_target");
		std::cout << "Before assignment: " << assigned << std::endl;
		assigned = original;
		std::cout << "After assignment: " << assigned << std::endl;
		
		// Test that target is properly copied
		std::cout << "Original target: " << original.get_target() << std::endl;
		std::cout << "Copy target: " << copy.get_target() << std::endl;
		std::cout << "Assigned target: " << assigned.get_target() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_boundary_conditions()
{
	std::cout << "=== Testing Boundary Conditions ===" << std::endl;
	try
	{
		// Test exact grade requirements
		std::cout << "--- Shrubbery Form (sign: 145, exec: 137) ---" << std::endl;
		ShrubberyCreationForm	shrubbery("boundary_test");
		Bureaucrat	exactSigner("ExactSigner", 145);
		Bureaucrat	exactExecutor("ExactExecutor", 137);
		
		exactSigner.sign_form(shrubbery);
		exactExecutor.execute_form(shrubbery);
		
		std::cout << "\n--- Robotomy Form (sign: 72, exec: 45) ---" << std::endl;
		RobotomyRequestForm	robotomy("boundary_robot");
		Bureaucrat	robotSigner("RobotSigner", 72);
		Bureaucrat	robotExecutor("RobotExecutor", 45);
		
		robotSigner.sign_form(robotomy);
		robotExecutor.execute_form(robotomy);
		
		std::cout << "\n--- Presidential Form (sign: 25, exec: 5) ---" << std::endl;
		PresidentialPardonForm	pardon("boundary_citizen");
		Bureaucrat	pardonSigner("PardonSigner", 25);
		Bureaucrat	pardonExecutor("PardonExecutor", 5);
		
		pardonSigner.sign_form(pardon);
		pardonExecutor.execute_form(pardon);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main()
{
	test_shrubbery_creation();
	test_robotomy_request();
	test_presidential_pardon();
	test_insufficient_grade_to_sign();
	test_insufficient_grade_to_execute();
	test_execution_without_signing();
	test_all_forms_complete_workflow();
	test_form_inheritance_and_polymorphism();
	test_copy_and_assignment();
	test_boundary_conditions();
	
	return (0);
}