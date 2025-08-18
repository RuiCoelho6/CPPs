#include "Bureaucrat.hpp"

void	testValidBureaucrats()
{
	std::cout << "=== Testing Valid Bureaucrats ===" << std::endl;
	try
	{
		Bureaucrat alice("Alice", 1);
		std::cout << alice << std::endl;
		Bureaucrat bob("Bob", 75);
		std::cout << bob << std::endl;
		Bureaucrat charlie("Charlie", 150);
		std::cout << charlie << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Unexpected exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testInvalidBureaucrats()
{
	std::cout << "=== Testing Invalid Bureaucrats ===" << std::endl;
	try
	{
		Bureaucrat invalid("Invalid", 0);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat invalid("Invalid", 151);
		std::cout << invalid << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testGradeModification()
{
	std::cout << "=== Testing Grade Modification ===" << std::endl;
	try
	{
		Bureaucrat worker("Worker", 75);
		std::cout << "Initial: " << worker << std::endl;
		worker.incrementGrade();
		std::cout << "After increment: " << worker << std::endl;
		worker.decrementGrade();
		std::cout << "After decrement: " << worker << std::endl;
		worker.decrementGrade();
		std::cout << "After another decrement: " << worker << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testGradeBoundaries()
{
	std::cout << "=== Testing Grade Boundaries ===" << std::endl;
	try
	{
		Bureaucrat topBureaucrat("TopBureaucrat", 1);
		std::cout << "Before increment: " << topBureaucrat << std::endl;
		topBureaucrat.incrementGrade();
		std::cout << "After increment: " << topBureaucrat << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception when incrementing grade 1: " << e.what() << std::endl;
	}
	try
	{
		Bureaucrat bottomBureaucrat("BottomBureaucrat", 150);
		std::cout << "Before decrement: " << bottomBureaucrat << std::endl;
		bottomBureaucrat.decrementGrade();
		std::cout << "After decrement: " << bottomBureaucrat << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception when decrementing grade 150: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

void	testCopyConstructorAndAssignment()
{
	std::cout << "=== Testing Copy Constructor and Assignment ===" << std::endl;
	try
	{
		Bureaucrat original("Original", 42);
		std::cout << "Original: " << original << std::endl;
		Bureaucrat copy(original);
		std::cout << "Copy: " << copy << std::endl;
		Bureaucrat assigned("TempName", 100);
		std::cout << "Before assignment: " << assigned << std::endl;
		assigned = original;
		std::cout << "After assignment: " << assigned << std::endl;
		original.incrementGrade();
		std::cout << "Original after increment: " << original << std::endl;
		std::cout << "Copy after original increment: " << copy << std::endl;
		std::cout << "Assigned after original increment: " << assigned << std::endl;
	}
	catch (std::exception& e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	std::cout << std::endl;
}

int	main()
{
	std::cout << "Welcome to the Bureaucratic Nightmare!" << std::endl;
	std::cout << "======================================" << std::endl << std::endl;
	testValidBureaucrats();
	testInvalidBureaucrats();
	testGradeModification();
	testGradeBoundaries();
	testCopyConstructorAndAssignment();
	std::cout << "Tests completed!" << std::endl;
	return (0);
}