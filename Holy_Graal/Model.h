#pragma once
#include "Labyrinth.h"
#include "Player.h"


class Model
{
public:
	Player player;
	Labyrinth labyrinth;
	bool CheckWidth(int x);
	bool CheckHeight(int y);
	int Move(std::string dir);
	int GetItem(std::string itemname);
	int DropItem(std::string itemname);
	void GenerateLevel();
	Model();
	~Model();
};

