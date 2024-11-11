#include "Zombie.hpp"

void	randomChump(std::string name)
{
	Zombie	tmp(name);
	
	tmp.announce();
}

/* 스택의 case 빠르지만 너무 큰 메모리를 할당할 수 없으며 스택 범위를 넘기면 바로 프로그램이 터진다 */
