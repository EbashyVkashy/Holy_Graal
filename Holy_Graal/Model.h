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
	Model();
	~Model();
};

