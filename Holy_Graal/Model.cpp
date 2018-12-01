#include "Model.h"
#include <iostream>
bool Model::CheckWidth(int x)
{
	if (x > 3 && x < 50)
	{
		return true;
	}
	return false;
}

bool Model::CheckHeight(int y)
{
	if (y > 3 && y < 50)
	{
		return true;
	}
	return false;
}

int Model::Move(std::string dir) //0-wrong name of door, 1-succes, 2-no door
{
	if (dir == "W" && labyrinth.rooms[player.pospoint].walls[0] == 1)
	{
		player.posx -= 1;
		player.pospoint -= labyrinth.height;
		player.life -= 1;
		return 1;
	}
	else if (dir == "N" && labyrinth.rooms[player.pospoint].walls[1] == 1)
	{
		player.posy += 1;
		player.pospoint += 1;
		player.life -= 1;
		return 1;
	}
	else if (dir == "E" && labyrinth.rooms[player.pospoint].walls[2] == 1)
	{
		player.posx += 1;
		player.pospoint += labyrinth.height;
		player.life -= 1;
		return 1;
	}
	else if (dir == "S" && labyrinth.rooms[player.pospoint].walls[3] == 1)
	{
		player.posy -= 1;
		player.pospoint -= 1;
		player.life -= 1;
		return 1;
	}
	else if (dir == "W" || dir == "N" || dir == "E" || dir == "S")
	{
		return 2;
	}
	return 0;
}

int Model::GetItem(std::string itemname) //0-wrong item name, 1-get key, 2-get chest, 3-no such item
{
	int stashpointer = labyrinth.rooms[player.pospoint].CheckStash(1);
	if (itemname == "key" && stashpointer >= 0)
	{
		Item tempitem;
		tempitem = labyrinth.rooms[player.pospoint].PassFromStash(stashpointer);
		labyrinth.rooms[player.pospoint].RemoveFromStash(stashpointer);
		player.AddToInventory(tempitem);
		return 1;
	}
	else if (itemname == "key" && stashpointer < 0)
	{
		return 3;
	}
	stashpointer = labyrinth.rooms[player.pospoint].CheckStash(2);
	if (itemname == "chest" && stashpointer >= 0)
	{
		return 2;
	}
	else if (itemname == "chest" && stashpointer < 0)
	{
		return 3;
	}
	return 0;
}

Model::Model()
{
}


Model::~Model()
{
}
