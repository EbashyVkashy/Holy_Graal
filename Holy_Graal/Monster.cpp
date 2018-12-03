#include "Monster.h"



void Monster::CreateMonster()
{
	int temp = rand() % 3;
	switch (temp)	
	{
	case 0:
		name = "gigant rat";
		break;
	case 1:
		name = "skeleton";
		break;
	case 2:
		name = "your boss";
		break;
	default:
		break;
	}
}

Monster::Monster()
{
}


Monster::~Monster()
{
}
