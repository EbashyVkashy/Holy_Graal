#pragma once
#include <vector>
#include "Item.h"

class Player
{
public:
	int posx;
	int posy;
	int pospoint;
	int life;
	std::vector<Item> inventory;
	void PlacePlayer(int x, int y, int maxy);
	void AddToInventory(Item &);
	Player();
	~Player();
};

