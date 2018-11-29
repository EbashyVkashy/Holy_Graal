#include "Room.h"



Room::Room()
{
	stashpoint = 0;
	for (int i = 0; i < 4; i++)
	{
		walls[i] = 0;
	}
}


Room::~Room()
{
}
