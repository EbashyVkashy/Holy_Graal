#include "Labyrinth.h"

void Labyrinth::LabCreation(int x, int y)
{
	width = x;
	height = y;
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{	
			Room temp;
			temp.RoomInit();
			rooms.push_back(temp);
		}
}

void Labyrinth::OpenSide(int x, int y, int dir)
{
	if ((x == 0 && dir == 0) || (y == 0 && dir == 3) || (x == (width - 1) && dir == 2) || (y == (height - 1) && dir == 1))
	{
		return;
	}

	rooms[x * height + y].OpenDoor(dir);
	switch (dir)
	{
	case 0:
		rooms[(x - 1) * height + y].OpenDoor(2);
		break;
	case 1:
		rooms[x * height + y + 1].OpenDoor(3);
		break;
	case 2:
		rooms[(x + 1) * height + y].OpenDoor(0);
		break;
	case 3:
		rooms[x * height + y - 1].OpenDoor(1);
		break;
	};
}

Labyrinth::Labyrinth()
{
}


Labyrinth::~Labyrinth()
{
}
