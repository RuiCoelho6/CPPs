#include "ClapTrap.hpp"

int main()
{
	std::cout << "=== ClapTrap Tests ===" << std::endl;
	
	// Test 1: Basic functionality
	std::cout << "\n--- Test 1: Basic Construction and Destruction ---" << std::endl;
	ClapTrap clap1("Clappy");
	
	// Test 2: Attack functionality
	std::cout << "\n--- Test 2: Attack Function ---" << std::endl;
	clap1.attack("Target1");
	clap1.attack("Target2");
	clap1.attack("Target3");
	
	// Test 3: Take damage functionality
	std::cout << "\n--- Test 3: Take Damage Function ---" << std::endl;
	clap1.takeDamage(3);
	clap1.takeDamage(4);
	
	// Test 4: Repair functionality
	std::cout << "\n--- Test 4: Repair Function ---" << std::endl;
	clap1.beRepaired(2);
	clap1.beRepaired(1);
	
	// Test 5: Energy depletion
	std::cout << "\n--- Test 5: Energy Depletion ---" << std::endl;
	ClapTrap clap2("EnergyTest");
	for (int i = 0; i < 12; i++)
	{
		std::cout << "Action " << (i + 1) << ": ";
		if (i % 2 == 0)
			clap2.attack("SomeTarget");
		else
			clap2.beRepaired(1);
	}
	
	// Test 6: Hit points depletion
	std::cout << "\n--- Test 6: Hit Points Depletion ---" << std::endl;
	ClapTrap clap3("HealthTest");
	clap3.takeDamage(15); // More than max hit points
	clap3.attack("SomeTarget"); // Should fail
	clap3.beRepaired(5); // Should fail
	clap3.takeDamage(5); // Should indicate already destroyed
	
	// Test 7: Copy constructor and assignment operator
	std::cout << "\n--- Test 7: Copy Constructor and Assignment ---" << std::endl;
	ClapTrap clap4("Original");
	clap4.takeDamage(2);
	
	// Copy constructor
	ClapTrap clap5(clap4);
	ClapTrap clap6("ToBeAssigned");
	// Assignment operator
	clap6 = clap4;
	
	std::cout << "Original: HP=" << clap4.getHitPoints() << ", EP=" << clap4.getEnergyPoints() << std::endl;
	std::cout << "Copy: HP=" << clap5.getHitPoints() << ", EP=" << clap5.getEnergyPoints() << std::endl;
	std::cout << "Assigned: HP=" << clap6.getHitPoints() << ", EP=" << clap6.getEnergyPoints() << std::endl;
	
	// Test 8: Default constructor
	std::cout << "\n--- Test 8: Default Constructor ---" << std::endl;
	ClapTrap defaultClap;
	defaultClap.attack("TestTarget");
	
	std::cout << "\n=== End of Tests ===" << std::endl;
	
	return 0;
}
