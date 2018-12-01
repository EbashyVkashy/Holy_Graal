#include "Player.h"



void Player::PlacePlayer(int x, int y, int maxy)
{
	posx = x;
	posy = y;
	pospoint = x * maxy + y;
	life = (x + y) * 2;
}

void Player::AddToInventory(Item & toinventory)
{
	inventory.push_back(toinventory);
}

Player::Player()
{
}


Player::~Player()
{
}
