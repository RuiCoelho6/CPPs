#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Default ClapTrap"), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "Default ClapTrap constructor" << std::endl;
}

ClapTrap::ClapTrap(std::string name): name(name), hit_points(10), energy_points(10), attack_damage(0)
{
	std::cout << "ClapTrap " << this->name << " was created" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hit_points(other.hit_points), energy_points(other.energy_points), attack_damage(other.attack_damage)
{
	std::cout << "Copy constructor called for ClapTrap " << this->name << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " was destroyed" << std::endl;
}

ClapTrap	&ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

void	ClapTrap::attack(const std::string& target)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and cannot attack" << std::endl;
		return ;
	}
	if (this->energy_points > 0)
		{
			std::cout << "ClapTrap " << this->name << " deals " << this->attack_damage << " points of damage to " << target << std::endl;
			this->energy_points -= 1;
		}
	else
		std::cout << "ClapTrap " << this->name << " has no energy to perform this action" << std::endl;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and cannot take damage" << std::endl;
		return ;
	}
	std::cout << "ClapTrap " << this->name << " took " << amount << " points of damage" << std::endl;
	this->hit_points -= amount;
	if (this->hit_points < 0)
		this->hit_points = 0;
	std::cout << "ClapTrap " << this->name << "'s current HP is " << this->hit_points << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->name << " is dead and cannot be repaired" << std::endl;
		return ;
	}
	if (this->energy_points > 0)
	{
		int	temp_hp = this->hit_points;
		this->hit_points += amount;
		std::cout << "ClapTrap " << this->name << "'s hp was repaired from " << temp_hp << " to " << this->hit_points << std::endl;
		this->energy_points -= 1;
	}
	else
		std::cout << "ClapTrap " << this->name << " has no energy to perform this action" << std::endl;
}

int	ClapTrap::getHitPoints(void) const
{
	return (this->hit_points);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (this->energy_points);
}
