#include "ScavTrap.hpp"

ScavTrap::ScavTrap(): ClapTrap("Default ScavTrap")
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "Default ScavTrap constructor" << std::endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "ScavTrap " << this->name << " was created" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &other): ClapTrap(other)
{
	this->hit_points = 100;
	this->energy_points = 50;
	this->attack_damage = 20;
	std::cout << "Copy construtor called for ScavTrap " << this->name << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " was destroyed" << std::endl;
}

ScavTrap	&ScavTrap::operator=(const ScavTrap &other)
{
	std::cout << "Copy assignment operator called for ScavTrap " << this->name << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

void	ScavTrap::attack(const std::string& target)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ScavTrap " << this->name << " is dead and cannot attack" << std::endl;
		return ;
	}
	if (this->energy_points > 0)
		{
			std::cout << "ScavTrap " << this->name << " deals " << this->attack_damage << " points of damage to " << target << std::endl;
			this->energy_points -= 1;
		}
	else
		std::cout << "ScavTrap " << this->name << " has no energy to perform this action" << std::endl;
}

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << this->name << " is in guard gate mode" << std::endl;
}
