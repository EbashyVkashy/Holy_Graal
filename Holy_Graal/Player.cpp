#include "Player.h"



void Player::PlacePlayer(int x, int y, int maxy)
{
	posx = x;
	posy = y;
	pospoint = x * maxy + y;
	life = (x + y) * 5;
}

void Player::AddToInventory(Item & toinventory)
{
	inventory.push_back(toinventory);
}

int Player::CheckInventory(int checkid)
{
	for (int i = 0; i < inventory.size(); i++)
	{
		if (inventory[i].itemid == checkid)
		{
			return i;
		}
	}
	return -1;
}

Item Player::PassFromInv(int pointvector)
{
	return inventory[pointvector];
}

void Player::RemoveFromInv(int pointvector)
{
	inventory.erase(inventory.begin() + pointvector);
}

Player::Player()
{
}


Player::~Player()
{
}
