#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap
{
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &other);
		FragTrap	&operator=(const FragTrap &other);
		void	attack(const std::string& target);
		void	highFivesGuys(void);
		~FragTrap();

		
		int	getHitPoints(void) const
		{
			return hit_points;
		}
		int	getEnergyPoints(void) const
		{
			return energy_points;
		}
		int	getAttackDamage(void) const
		{
			return attack_damage;
		}
};

#endif
