#include "Model.h"

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
	if (dir == "W" && labyrinth.rooms[player.posx * labyrinth.height + player.posy].walls[0] == 1)
	{
		player.posx -= 1;
		player.life -= 1;
		return 1;
	}
	else if (dir == "N" && labyrinth.rooms[player.posx * labyrinth.height + player.posy].walls[1] == 1)
	{
		player.posy += 1;
		player.life -= 1;
		return 1;
	}
	else if (dir == "E" && labyrinth.rooms[player.posx * labyrinth.height + player.posy].walls[2] == 1)
	{
		player.posx += 1;
		player.life -= 1;
		return 1;
	}
	else if (dir == "S" && labyrinth.rooms[player.posx * labyrinth.height + player.posy].walls[3] == 1)
	{
		player.posy -= 1;
		player.life -= 1;
		return 1;
	}
	else if (dir == "W" || dir == "N" || dir == "E" || dir == "S")
	{
		return 2;
	}
	return 0;
}

Model::Model()
{
}


Model::~Model()
{
}
