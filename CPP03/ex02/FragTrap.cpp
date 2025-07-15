#include "FragTrap.hpp"

FragTrap::FragTrap(): ClapTrap("Default FragTrap")
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "Default FragTrap constructor" << std::endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "FragTrap " << this->name << " was created" << std::endl;
}

FragTrap::FragTrap(const FragTrap &other): ClapTrap(other)
{
	this->hit_points = 100;
	this->energy_points = 100;
	this->attack_damage = 30;
	std::cout << "Copy construtor called for FragTrap " << this->name << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " was destroyed" << std::endl;
}

FragTrap	&FragTrap::operator=(const FragTrap &other)
{
	std::cout << "Copy assignment operator called for FragTrap " << this->name << std::endl;
	if (this != &other)
	{
		this->name = other.name;
		this->hit_points = other.hit_points;
		this->energy_points = other.energy_points;
		this->attack_damage = other.attack_damage;
	}
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (this->hit_points <= 0)
	{
		std::cout << "FragTrap " << this->name << " is dead and cannot attack" << std::endl;
		return ;
	}
	if (this->energy_points > 0)
		{
			std::cout << "FragTrap " << this->name << " deals " << this->attack_damage << " points of damage to " << target << std::endl;
			this->energy_points -= 1;
		}
	else
		std::cout << "FragTrap " << this->name << " has no energy to perform this action" << std::endl;
}

void	FragTrap::highFivesGuys()
{
	std::cout << "FragTrap " << this->name << " wants a High-five! 🙏" << std::endl;
}
