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
	Model();
	~Model();
};

