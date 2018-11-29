#pragma once
#include "Room.h"
#include <vector>

class Labyrinth
{
public:
	std::vector<Room> labyrinth;
	int enterx;
	int entery;
	int keyx;
	int keyy;
	int chestx;
	int chesty;
	Labyrinth();
	~Labyrinth();
};

