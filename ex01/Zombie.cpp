#include "Zombie.hpp"

Zombie::Zombie(void)
{	
}

Zombie::Zombie(std::string name) : name(name)
{
	// std::cout << this->name << " was born." << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->name << " is dead" << std::endl;
}

void	Zombie::announce(void)
{
	std::cout << this->name <<  ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void	Zombie::setName(std::string name)
{
	this->name = name;
}
