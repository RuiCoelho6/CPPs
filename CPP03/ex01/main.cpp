#include "ScavTrap.hpp"

int main()
{
	std::cout << "=== ClapTrap and ScavTrap Tests ===" << std::endl;
	
	// Test 1: Basic ClapTrap functionality (quick test)
	std::cout << "\n--- Test 1: Basic ClapTrap Construction ---" << std::endl;
	ClapTrap clap1("Clappy");
	clap1.attack("Target1");
	std::cout << "ClapTrap HP: " << clap1.getHitPoints() << ", EP: " << clap1.getEnergyPoints() << std::endl;
	
	// Test 2: Basic ScavTrap construction and destruction chain
	std::cout << "\n--- Test 2: ScavTrap Construction Chain ---" << std::endl;
	ScavTrap scav1("Scavvy");
	std::cout << "ScavTrap HP: " << scav1.getHitPoints() << ", EP: " << scav1.getEnergyPoints() << std::endl;
	
	// Test 3: ScavTrap vs ClapTrap attack comparison
	std::cout << "\n--- Test 3: Attack Function Comparison ---" << std::endl;
	std::cout << "ClapTrap attack:" << std::endl;
	clap1.attack("Enemy");
	std::cout << "ScavTrap attack:" << std::endl;
	scav1.attack("Enemy");
	
	// Test 4: ScavTrap special ability
	std::cout << "\n--- Test 4: ScavTrap Special Ability ---" << std::endl;
	scav1.guardGate();
	
	// Test 5: ScavTrap inherited functions
	std::cout << "\n--- Test 5: ScavTrap Inherited Functions ---" << std::endl;
	scav1.takeDamage(20);
	scav1.beRepaired(10);
	std::cout << "After damage and repair - HP: " << scav1.getHitPoints() << ", EP: " << scav1.getEnergyPoints() << std::endl;
	
	// Test 6: ScavTrap energy depletion (should take longer due to higher energy)
	std::cout << "\n--- Test 6: ScavTrap Energy Depletion Test ---" << std::endl;
	ScavTrap scav2("EnergyTest");
	for (int i = 0; i < 52; i++) // 50 energy + 2 extra to show depletion
	{
		if (i % 10 == 0) // Print every 10th action to avoid spam
			std::cout << "Action " << (i + 1) << ": ";
		if (i % 2 == 0)
			scav2.attack("Target");
		else
			scav2.beRepaired(1);
		if (i % 10 == 0)
			std::cout << "EP remaining: " << scav2.getEnergyPoints() << std::endl;
	}
	
	// Test 7: ScavTrap survivability test (higher HP)
	std::cout << "\n--- Test 7: ScavTrap Survivability Test ---" << std::endl;
	ScavTrap scav3("ToughGuy");
	scav3.takeDamage(50);  // Should survive this
	scav3.attack("StillAlive");
	scav3.takeDamage(60);  // Should die after this
	scav3.attack("ShouldFail");
	scav3.guardGate();     // Should work even if dead?
	
	// Test 8: Copy constructor and assignment (inheritance chain)
	std::cout << "\n--- Test 8: ScavTrap Copy Operations ---" << std::endl;
	ScavTrap scav4("Original");
	scav4.takeDamage(10);
	scav4.attack("Someone");
	
	// Copy constructor - should show both ClapTrap and ScavTrap construction
	ScavTrap scav5(scav4);
	
	// Assignment operator
	ScavTrap scav6("ToBeAssigned");
	scav6 = scav4;
	
	std::cout << "Original: HP=" << scav4.getHitPoints() << ", EP=" << scav4.getEnergyPoints() << std::endl;
	std::cout << "Copy: HP=" << scav5.getHitPoints() << ", EP=" << scav5.getEnergyPoints() << std::endl;
	std::cout << "Assigned: HP=" << scav6.getHitPoints() << ", EP=" << scav6.getEnergyPoints() << std::endl;
	
	// Test 9: Default constructor
	std::cout << "\n--- Test 9: ScavTrap Default Constructor ---" << std::endl;
	ScavTrap defaultScav;
	defaultScav.attack("TestTarget");
	defaultScav.guardGate();
	
	// Test 10: Mixed operations
	std::cout << "\n--- Test 10: Mixed ClapTrap and ScavTrap Operations ---" << std::endl;
	ClapTrap *clap_ptr = new ClapTrap("HeapClap");
	ScavTrap *scav_ptr = new ScavTrap("HeapScav");
	
	clap_ptr->attack("CommonEnemy");
	scav_ptr->attack("CommonEnemy");
	scav_ptr->guardGate();
	
	delete clap_ptr;
	delete scav_ptr;
	
	std::cout << "\n--- Test 11: Destruction Chain Observation ---" << std::endl;
	{
		ScavTrap tempScav("TempScav");
		tempScav.guardGate();
		// Watch the destruction order when this scope ends
	}
	
	std::cout << "\n=== End of Tests ===" << std::endl;
	
	return 0;
}