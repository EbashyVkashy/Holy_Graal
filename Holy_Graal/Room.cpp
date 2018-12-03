#include "Room.h"

void Room::RoomInit()
{
	for (int i = 0; i < 4; i++)
	{
			walls[i] = 0;
	}
	light = 1;
}

void Room::AddToStash(Item &item)
{
	stash.push_back(item);
}

int Room::CheckStash(int checkid)
{
	for (int i = 0; i < stash.size(); i++)
	{
		if (stash[i].itemid == checkid)
		{
			return i;
		}
	}
	return -1;
}

int Room::CheckStashFood(std::string foodcheck)
{
	for (int i = 0; i < stash.size(); i++)
	{
		if (stash[i].name == foodcheck)
		{
			return i;
		}
	}
	return -1;
}

Item Room::PassFromStash(int pointvector)
{
	return stash[pointvector];
}

void Room::RemoveFromStash(int pointvector)
{
	stash.erase(stash.begin() + pointvector);
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
