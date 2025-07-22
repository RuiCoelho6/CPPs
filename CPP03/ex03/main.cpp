#include "DiamondTrap.hpp"

int main()
{
	std::cout << "=== DiamondTrap Tests ===" << std::endl;
	
	// Test 1: Basic DiamondTrap construction
	std::cout << "\n--- Test 1: DiamondTrap Construction ---" << std::endl;
	DiamondTrap diamond1("Diamond1");
	// Explicitly qualify getHitPoints and getEnergyPoints
	std::cout << "DiamondTrap HP: " << diamond1.getHitPoints() << ", EP: " << diamond1.getEnergyPoints() << std::endl;
	
	// Test 2: DiamondTrap whoAmI function
	std::cout << "\n--- Test 2: DiamondTrap whoAmI ---" << std::endl;
	diamond1.whoAmI();
	
	// Test 3: DiamondTrap attack (should use ScavTrap's attack)
	std::cout << "\n--- Test 3: DiamondTrap Attack ---" << std::endl;
	diamond1.attack("Enemy"); // This should now correctly call DiamondTrap's own attack, which calls ScavTrap::attack
	
	// Test 4: DiamondTrap inherited special abilities
	std::cout << "\n--- Test 4: DiamondTrap Special Abilities ---" << std::endl;
	diamond1.highFivesGuys();  // From FragTrap (now defined in DiamondTrap.cpp)
	diamond1.guardGate();      // From ScavTrap (now defined in DiamondTrap.cpp)
	
	// Test 5: DiamondTrap stats verification
	std::cout << "\n--- Test 5: DiamondTrap Stats Verification ---" << std::endl;
	std::cout << "Expected: HP=100 (FragTrap), EP=50 (ScavTrap), Attack=30 (FragTrap)" << std::endl;
	// Explicitly qualify getHitPoints and getEnergyPoints
	std::cout << "Actual: HP=" << diamond1.getHitPoints() << ", EP=" << diamond1.getEnergyPoints() << std::endl;
	
	// Test 6: DiamondTrap damage and repair
	std::cout << "\n--- Test 6: DiamondTrap Damage and Repair ---" << std::endl;
	// Explicitly qualify takeDamage and beRepaired
	diamond1.takeDamage(30);
	diamond1.beRepaired(15);
	diamond1.whoAmI();
	
	// Test 7: DiamondTrap copy constructor
	std::cout << "\n--- Test 7: DiamondTrap Copy Constructor ---" << std::endl;
	DiamondTrap diamond2(diamond1);
	diamond2.whoAmI();
	
	// Test 8: DiamondTrap assignment operator
	std::cout << "\n--- Test 8: DiamondTrap Assignment Operator ---" << std::endl;
	DiamondTrap diamond3("ToBeAssigned");
	diamond3 = diamond1;
	diamond3.whoAmI();
	
	// Test 9: DiamondTrap default constructor
	std::cout << "\n--- Test 9: DiamondTrap Default Constructor ---" << std::endl;
	DiamondTrap defaultDiamond;
	defaultDiamond.whoAmI();
	defaultDiamond.attack("TestTarget"); // This should now correctly call DiamondTrap's own attack
	
	// Test 10: Multiple DiamondTrap interactions
	std::cout << "\n--- Test 10: Multiple DiamondTrap Interactions ---" << std::endl;
	DiamondTrap diamond4("Attacker");
	DiamondTrap diamond5("Defender");
	
	diamond4.attack("Defender"); // This should now correctly call DiamondTrap's own attack
	diamond5.takeDamage(30); // Explicitly qualify takeDamage
	diamond5.whoAmI();
	diamond4.highFivesGuys();
	diamond5.guardGate();
	
	// Test 11: DiamondTrap energy depletion
	std::cout << "\n--- Test 11: DiamondTrap Energy Depletion ---" << std::endl;
	DiamondTrap diamond6("EnergyTest");
	for (int i = 0; i < 52; i++) // 50 energy + 2 extra
	{
		if (i % 10 == 0)
			std::cout << "Action " << (i + 1) << ": ";
		if (i % 2 == 0)
			diamond6.attack("Target"); // This should now correctly call DiamondTrap's own attack
		else
			diamond6.beRepaired(1); // Explicitly qualify beRepaired
		if (i % 10 == 0)
			std::cout << "EP remaining: " << diamond6.ScavTrap::getEnergyPoints() << std::endl; // Explicitly qualify getEnergyPoints
	}
	
	// Test 12: DiamondTrap survival test
	std::cout << "\n--- Test 12: DiamondTrap Survival Test ---" << std::endl;
	DiamondTrap diamond7("Survivor");
	diamond7.takeDamage(50); // Explicitly qualify takeDamage
	diamond7.attack("StillAlive"); // This should now correctly call DiamondTrap's own attack
	diamond7.whoAmI();
	diamond7.takeDamage(60); // Should die, explicitly qualify takeDamage
	diamond7.attack("ShouldFail"); // This should now correctly call DiamondTrap's own attack
	diamond7.whoAmI(); // Should still work?
	
	// Test 13: Polymorphism test
	std::cout << "\n--- Test 13: Polymorphism Test ---" << std::endl;
	ClapTrap* ptr1 = new DiamondTrap("PolyDiamond");
	FragTrap* ptr2 = new DiamondTrap("PolyDiamond2");
	ScavTrap* ptr3 = new DiamondTrap("PolyDiamond3");
	
	// These calls will use the base class's attack because attack is not virtual in ClapTrap
	ptr1->attack("PolyTarget");
	ptr2->attack("PolyTarget");
	ptr3->attack("PolyTarget");
	
	// Note: whoAmI() won't work through base class pointers without virtual functions
	
	delete ptr1;
	delete ptr2;
	delete ptr3;
	
	// Test 14: All abilities showcase
	std::cout << "\n--- Test 14: All Abilities Showcase ---" << std::endl;
	DiamondTrap finalDiamond("UltimateBot");
	finalDiamond.whoAmI();
	finalDiamond.attack("FinalEnemy"); // This should now correctly call DiamondTrap's own attack
	finalDiamond.highFivesGuys();
	finalDiamond.guardGate();
	finalDiamond.takeDamage(25); // Explicitly qualify takeDamage
	finalDiamond.beRepaired(10); // Explicitly qualify beRepaired
	finalDiamond.whoAmI();
	
	std::cout << "\n=== End of DiamondTrap Tests ===" << std::endl;
	
	return 0;
}
