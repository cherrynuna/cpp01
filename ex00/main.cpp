#include "Zombie.hpp"

int	main(void)
{
	Zombie	stack("stack1");
	Zombie	*heap = newZombie("heap1");

	stack.announce();
	heap->announce();
	randomChump("heap2");

	delete heap;//프리
	// heap->announce(); <- heap-use-after-free case
	return (0);
}
