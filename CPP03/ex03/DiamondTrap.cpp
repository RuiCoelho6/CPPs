#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default DiamondTrap_clap_name"), FragTrap(), ScavTrap(), name("Default DiamondTrap")
{
	this->hit_points = FragTrap::hit_points; // Should be 100
	this->energy_points = ScavTrap::energy_points; // Should be 50
	std::cout << "Diamond " << std::endl;
	this->attack_damage = FragTrap::attack_damage; // Should be 30
	std::cout << "Default DiamondTrap constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), FragTrap(name + "_Clap_name"), ScavTrap(name + "_Clap_name"), name(name)
{
	this->name = name;
	this->hit_points = FragTrap::hit_points; // Should be 100
	this->energy_points = ScavTrap::energy_points; // Should be 50
	this->attack_damage = FragTrap::attack_damage; // Should be 30
	std::cout << "DiamondTrap " << this->name << " was created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other.name + "_Clap_name"), FragTrap(other.name + "_Clap_name"), ScavTrap(other.name + "_Clap_name"), name(other.name)
{
	this->name = name;
	this->hit_points = FragTrap::hit_points;
	this->energy_points = ScavTrap::energy_points;
	this->attack_damage = FragTrap::attack_damage;
	std::cout << "Copy constructor called for DiamondTrap " << this->name << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->name << " was destroyed" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "Copy assignment operator called for DiamondTrap " << this->name << std::endl;
	if (this != &other)
	{
		this->name = other.name;
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
