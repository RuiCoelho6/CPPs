#include "DiamondTrap.hpp"

// Default constructor: Initialize base classes in the order they are declared in DiamondTrap.hpp
// (ScavTrap then FragTrap). ClapTrap is virtually inherited, so it's initialized by the most-derived class.
DiamondTrap::DiamondTrap(): ClapTrap("Default DiamondTrap_clap_name"), ScavTrap(), FragTrap(), name("Default DiamondTrap")
{
	// ClapTrap::name is already set in ClapTrap constructor via explicit initialization
	// For virtual inheritance, ClapTrap's members are initialized by the most-derived class.
	// So, we explicitly initialize ClapTrap here.
	// The hit_points, energy_points, and attack_damage are set based on FragTrap and ScavTrap
	// as per the subject's requirements for DiamondTrap.
	this->hit_points = FragTrap::hit_points; // Should be 100
	this->energy_points = ScavTrap::energy_points; // Should be 50
	this->attack_damage = FragTrap::attack_damage; // Should be 30
	std::cout << "Default DiamondTrap constructor" << std::endl;
}

// Parameterized constructor: Initialize base classes in the correct order.
DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	// ClapTrap::name is already set in ClapTrap constructor via explicit initialization
	this->hit_points = FragTrap::hit_points; // Should be 100
	this->energy_points = ScavTrap::energy_points; // Should be 50
	this->attack_damage = FragTrap::attack_damage; // Should be 30
	std::cout << "DiamondTrap " << this->name << " was created" << std::endl;
}

// Copy constructor: Initialize base classes in the correct order, including ClapTrap explicitly.
DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	ClapTrap::name = this->name + "_clap_name"; // Ensure ClapTrap's name is also updated for the copy
	this->hit_points = FragTrap::hit_points; // Inherit stats from FragTrap/ScavTrap
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "Copy constructor called for DiamondTrap " << this->name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " was destroyed" << std::endl;
}

DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "Copy assignment operator called for DiamondTrap " << this->name << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		ClapTrap::name = this->name + "_clap_name"; // Update ClapTrap's name for assignment
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::guardGate()
{
	ScavTrap::guardGate();
}

void	DiamondTrap::highFivesGuys(void)
{
	FragTrap::highFivesGuys();
}

void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap name: " << this->name << ", ClapTrap name: " << ClapTrap::name << std::endl;
}
