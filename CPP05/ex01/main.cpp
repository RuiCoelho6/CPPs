#include "Bureaucrat.hpp"
#include "Form.hpp"

void	test_valid_forms()
{
	std::cout << "=== Testing _valid Forms ===" << std::endl;
	try
	{
		Form	taxForm("Tax Form", 50, 30);
		std::cout << taxForm << std::endl;
		Form	permit("Building Permit", 1, 1);
		std::cout << permit << std::endl;
		Form	application("Job Application", 150, 100);
		std::cout << application << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_invalid_forms()
{
	std::cout << "=== Testing Invalid Forms ===" << std::endl;
	try
	{
		Form	invalid("Invalid Form", 0, 50);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception for grade 0: " << e.what() << std::endl;
	}
	try
	{
		Form	invalid("Invalid Form", 50, 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception for grade 151: " << e.what() << std::endl;
	}
	try
	{
		Form	invalid("Invalid Form", -5, 10);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception for negative grade: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_form_signing()
{
	std::cout << "=== Testing Form Signing ===" << std::endl;
	try
	{
		Form	importantForm("Important Document", 25, 10);
		std::cout << "Before signing: " << importantForm << std::endl;
		
		Bureaucrat	highRankBureaucrat("Alice", 20);
		std::cout << "High rank bureaucrat: " << highRankBureaucrat << std::endl;
		highRankBureaucrat.sign_form(importantForm);
		std::cout << "After signing: " << importantForm << std::endl;
		
		// Try to sign again
		highRankBureaucrat.sign_form(importantForm);
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_form_signing_failure()
{
	std::cout << "=== Testing Form Signing Failure ===" << std::endl;
	try
	{
		Form	restrictedForm("Top Secret Document", 5, 1);
		std::cout << "Restricted form: " << restrictedForm << std::endl;
		
		Bureaucrat	lowRankBureaucrat("Bob", 50);
		std::cout << "Low rank bureaucrat: " << lowRankBureaucrat << std::endl;
		lowRankBureaucrat.sign_form(restrictedForm);
		std::cout << "After attempt: " << restrictedForm << std::endl;
		
		// Now try with someone who can sign it
		Bureaucrat	highRankBureaucrat("Charlie", 3);
		std::cout << "High rank bureaucrat: " << highRankBureaucrat << std::endl;
		highRankBureaucrat.sign_form(restrictedForm);
		std::cout << "After successful signing: " << restrictedForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_boundary_grades()
{
	std::cout << "=== Testing Boundary Grades ===" << std::endl;
	try
	{
		Form	extremeForm("Extreme Form", 1, 150);
		std::cout << "Extreme form: " << extremeForm << std::endl;
		
		Bureaucrat	topBureaucrat("TopDog", 1);
		std::cout << "Top bureaucrat: " << topBureaucrat << std::endl;
		topBureaucrat.sign_form(extremeForm);
		std::cout << "After signing: " << extremeForm << std::endl;
		
		Form	anotherForm("Another Form", 150, 1);
		std::cout << "Another form: " << anotherForm << std::endl;
		
		Bureaucrat	bottomBureaucrat("Nobody", 150);
		std::cout << "Bottom bureaucrat: " << bottomBureaucrat << std::endl;
		bottomBureaucrat.sign_form(anotherForm);
		std::cout << "After attempt: " << anotherForm << std::endl;
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
		Form	original("Original Form", 42, 21);
		std::cout << "Original: " << original << std::endl;
		
		// Sign the original
		Bureaucrat	signer("Signer", 40);
		signer.sign_form(original);
		std::cout << "Original after signing: " << original << std::endl;
		
		// Test copy constructor
		Form	copy(original);
		std::cout << "Copy: " << copy << std::endl;
		
		// Test assignment
		Form	assigned("Temp", 100, 100);
		std::cout << "Before assignment: " << assigned << std::endl;
		assigned = original;
		std::cout << "After assignment: " << assigned << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	test_original_bureaucrat_functions()
{
	std::cout << "=== Testing Original Bureaucrat Functions Still Work ===" << std::endl;
	try
	{
		Bureaucrat	worker("Worker", 75);
		std::cout << "Initial: " << worker << std::endl;
		worker.increment_grade();
		std::cout << "After increment: " << worker << std::endl;
		worker.decrement_grade();
		std::cout << "After decrement: " << worker << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main()
{
	test_valid_forms();
	test_invalid_forms();
	test_form_signing();
	test_form_signing_failure();
	test_boundary_grades();
	test_copy_and_assignment();
	test_original_bureaucrat_functions();
	return (0);
}