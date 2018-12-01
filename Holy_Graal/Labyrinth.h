#pragma once
#include "Room.h"
#include <vector>

class Labyrinth
{
public:
	std::vector<Room> rooms;
	int width;
	int height;
	int enterx;
	int entery;
	int keyx;
	int keyy;
	int chestx;
	int chesty;
	void LabCreation(int x, int y);
	void OpenSide(int x, int y, int dir);
	Labyrinth();
	~Labyrinth();
};

