#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	std::cout << "=== ClapTrap, ScavTrap, and FragTrap Tests ===" << std::endl;
	
	// Test 1: Basic ClapTrap functionality (quick test)
	std::cout << "\n--- Test 1: Basic ClapTrap Construction ---" << std::endl;
	ClapTrap clap1("Clappy");
	clap1.attack("Target1");
	std::cout << "ClapTrap HP: " << clap1.getHitPoints() << ", EP: " << clap1.getEnergyPoints() << std::endl;
	
	// Test 2: Basic ScavTrap construction and destruction chain
	std::cout << "\n--- Test 2: ScavTrap Construction Chain ---" << std::endl;
	ScavTrap scav1("Scavvy");
	std::cout << "ScavTrap HP: " << scav1.getHitPoints() << ", EP: " << scav1.getEnergyPoints() << std::endl;
	
	// Test 3: Basic FragTrap construction and destruction chain
	std::cout << "\n--- Test 3: FragTrap Construction Chain ---" << std::endl;
	FragTrap frag1("Fraggy");
	std::cout << "FragTrap HP: " << frag1.getHitPoints() << ", EP: " << frag1.getEnergyPoints() << std::endl;
	
	// Test 4: Attack function comparison (ClapTrap vs ScavTrap vs FragTrap)
	std::cout << "\n--- Test 4: Attack Function Comparison ---" << std::endl;
	std::cout << "ClapTrap attack:" << std::endl;
	clap1.attack("Enemy");
	std::cout << "ScavTrap attack:" << std::endl;
	scav1.attack("Enemy");
	std::cout << "FragTrap attack:" << std::endl;
	frag1.attack("Enemy");
	
	// Test 5: Special abilities comparison
	std::cout << "\n--- Test 5: Special Abilities ---" << std::endl;
	std::cout << "ScavTrap special ability:" << std::endl;
	scav1.guardGate();
	std::cout << "FragTrap special ability:" << std::endl;
	frag1.highFivesGuys();
	
	// Test 6: FragTrap inherited functions
	std::cout << "\n--- Test 6: FragTrap Inherited Functions ---" << std::endl;
	frag1.takeDamage(30);
	frag1.beRepaired(15);
	std::cout << "After damage and repair - HP: " << frag1.getHitPoints() << ", EP: " << frag1.getEnergyPoints() << std::endl;
	
	// Test 7: FragTrap energy depletion test (higher energy than ClapTrap)
	std::cout << "\n--- Test 7: FragTrap Energy Depletion Test ---" << std::endl;
	FragTrap frag2("EnergyTest");
	for (int i = 0; i < 102; i++) // 100 energy + 2 extra to show depletion
	{
		if (i % 20 == 0) // Print every 20th action to avoid spam
			std::cout << "Action " << (i + 1) << ": ";
		if (i % 2 == 0)
			frag2.attack("Target");
		else
			frag2.beRepaired(1);
		if (i % 20 == 0)
			std::cout << "EP remaining: " << frag2.getEnergyPoints() << std::endl;
	}
	
	// Test 8: FragTrap survivability test (high HP)
	std::cout << "\n--- Test 8: FragTrap Survivability Test ---" << std::endl;
	FragTrap frag3("ToughGuy");
	frag3.takeDamage(50);  // Should survive this easily
	frag3.attack("StillAlive");
	frag3.highFivesGuys();
	frag3.takeDamage(60);  // Should die after this (total 110 damage)
	frag3.attack("ShouldFail");
	frag3.highFivesGuys();     // Should work even if dead?
	
	// Test 9: FragTrap copy constructor and assignment
	std::cout << "\n--- Test 9: FragTrap Copy Operations ---" << std::endl;
	FragTrap frag4("Original");
	frag4.takeDamage(20);
	frag4.attack("Someone");
	frag4.highFivesGuys();
	
	// Copy constructor - should show both ClapTrap and FragTrap construction
	FragTrap frag5(frag4);
	
	// Assignment operator
	FragTrap frag6("ToBeAssigned");
	frag6 = frag4;
	
	std::cout << "Original: HP=" << frag4.getHitPoints() << ", EP=" << frag4.getEnergyPoints() << std::endl;
	std::cout << "Copy: HP=" << frag5.getHitPoints() << ", EP=" << frag5.getEnergyPoints() << std::endl;
	std::cout << "Assigned: HP=" << frag6.getHitPoints() << ", EP=" << frag6.getEnergyPoints() << std::endl;
	
	// Test 10: FragTrap default constructor
	std::cout << "\n--- Test 10: FragTrap Default Constructor ---" << std::endl;
	FragTrap defaultFrag;
	defaultFrag.attack("TestTarget");
	defaultFrag.highFivesGuys();
	
	// Test 11: ScavTrap vs FragTrap stats comparison
	std::cout << "\n--- Test 11: ScavTrap vs FragTrap Stats Comparison ---" << std::endl;
	ScavTrap scavCompare("ScavCompare");
	FragTrap fragCompare("FragCompare");
	
	std::cout << "ScavTrap stats - HP: " << scavCompare.getHitPoints() << ", EP: " << scavCompare.getEnergyPoints() << std::endl;
	std::cout << "FragTrap stats - HP: " << fragCompare.getHitPoints() << ", EP: " << fragCompare.getEnergyPoints() << std::endl;
	
	std::cout << "ScavTrap attack damage test:" << std::endl;
	scavCompare.attack("DamageTest");
	std::cout << "FragTrap attack damage test:" << std::endl;
	fragCompare.attack("DamageTest");
	
	// Test 12: Mixed operations with all three types
	std::cout << "\n--- Test 12: Mixed Operations with All Types ---" << std::endl;
	ClapTrap *clap_ptr = new ClapTrap("HeapClap");
	ScavTrap *scav_ptr = new ScavTrap("HeapScav");
	FragTrap *frag_ptr = new FragTrap("HeapFrag");
	
	clap_ptr->attack("CommonEnemy");
	scav_ptr->attack("CommonEnemy");
	frag_ptr->attack("CommonEnemy");
	
	scav_ptr->guardGate();
	frag_ptr->highFivesGuys();
	
	delete clap_ptr;
	delete scav_ptr;
	delete frag_ptr;
	
	// Test 13: ScavTrap specific tests (from original)
	std::cout << "\n--- Test 13: ScavTrap Energy Depletion Test ---" << std::endl;
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
	
	// Test 14: ScavTrap survivability test
	std::cout << "\n--- Test 14: ScavTrap Survivability Test ---" << std::endl;
	ScavTrap scav3("ToughGuy");
	scav3.takeDamage(50);  // Should survive this
	scav3.attack("StillAlive");
	scav3.takeDamage(60);  // Should die after this
	scav3.attack("ShouldFail");
	scav3.guardGate();     // Should work even if dead?
	
	// Test 15: ScavTrap copy operations
	std::cout << "\n--- Test 15: ScavTrap Copy Operations ---" << std::endl;
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
	
	// Test 16: ScavTrap default constructor
	std::cout << "\n--- Test 16: ScavTrap Default Constructor ---" << std::endl;
	ScavTrap defaultScav;
	defaultScav.attack("TestTarget");
	defaultScav.guardGate();
	
	// Test 17: Destruction chain observation
	std::cout << "\n--- Test 17: Destruction Chain Observation ---" << std::endl;
	{
		std::cout << "Creating ScavTrap in scope:" << std::endl;
		ScavTrap tempScav("TempScav");
		tempScav.guardGate();
		std::cout << "Creating FragTrap in scope:" << std::endl;
		FragTrap tempFrag("TempFrag");
		tempFrag.highFivesGuys();
		// Watch the destruction order when this scope ends
		std::cout << "Leaving scope - watch destruction order:" << std::endl;
	}
	
	// Test 18: All classes special abilities showcase
	std::cout << "\n--- Test 18: Special Abilities Showcase ---" << std::endl;
	ScavTrap finalScav("FinalScav");
	FragTrap finalFrag("FinalFrag");
	
	std::cout << "ScavTrap entering guard mode:" << std::endl;
	finalScav.guardGate();
	std::cout << "FragTrap requesting high-fives:" << std::endl;
	finalFrag.highFivesGuys();
	
	std::cout << "\n=== End of Tests ===" << std::endl;
	
	return 0;
}
