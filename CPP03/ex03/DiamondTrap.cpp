#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(): ClapTrap("Default DiamondTrap_clap_name"), ScavTrap(), FragTrap(), name("Default DiamondTrap")
{
	this->hit_points = FragTrap::hit_points; // Should be 100
	this->energy_points = ScavTrap::energy_points; // Should be 50
	this->attack_damage = FragTrap::attack_damage; // Should be 30
	std::cout << "Default DiamondTrap constructor" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), name(name)
{
	this->hit_points = FragTrap::hit_points; // Should be 100
	this->energy_points = ScavTrap::energy_points; // Should be 50
	this->attack_damage = FragTrap::attack_damage; // Should be 30
	std::cout << "DiamondTrap " << this->name << " was created" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other): ClapTrap(other), ScavTrap(other), FragTrap(other), name(other.name)
{
	ClapTrap::name = this->name + "_clap_name";
	this->hit_points = FragTrap::hit_points;
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
		ClapTrap::name = this->name + "_clap_name";
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
