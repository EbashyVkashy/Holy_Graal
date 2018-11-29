#pragma once
#include <vector>
#include "Item.h"

class Room
{
public:
	int walls[4]; // 0-West, 1-North, 2-East, 3-South
	int stashpoint;
	std::vector<Item> stash;
	int light; //0-no light, 1-light, 2-lighted with torch
	Room();
	~Room();
};

