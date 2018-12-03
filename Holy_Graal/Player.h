#pragma once
#include <vector>
#include "Item.h"

class Player
{
public:
	int posx;
	int posy;
	int prevposx;
	int prevposy;
	int pospoint;
	int prevpospoint;
	int life;
	int initlife;
	std::vector<Item> inventory;
	void PlacePlayer(int x, int y, int maxy);
	void AddToInventory(Item &);
	int CheckInventory(int checkid); // -1 - no such item, 0-100 item pos in vector
	Item PassFromInv(int pointvector);
	void RemoveFromInv(int pointvector);
	Player();
	~Player();
};

