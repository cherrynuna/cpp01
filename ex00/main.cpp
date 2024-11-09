#include "Zombie.hpp"

int	main(void)
{
	Zombie	stack("stack");
	Zombie	*heap = newZombie("heap");

	stack.announce();
	heap->announce();
	randomChump("stack2");

	delete heap;//프리
	// heap->announce(); <- heap-use-after-free case
	return (0);
}
