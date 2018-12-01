#include "Room.h"

void Room::RoomInit()
{
for (int i = 0; i < 4; i++)
	{
		walls[i] = 0;
	}
}

void Room::AddToStash(Item &item)
{
	stash.push_back(item);
}

bool Room::RemoveFromStash(Item & item)
{
	int quantity = stash.size();
	for (int i = 0; i < quantity; i++)
	{
		if (stash[i].itemid == item.itemid)
		{
			stash.erase(stash.begin() + i);
			return true;
		}
	}
	return false;
}

void Room::OpenDoor(int dir)
{
	walls[dir] = 1;
}

Room::Room()
{
}


Room::~Room()
{
}
