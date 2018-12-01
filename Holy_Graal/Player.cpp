#include "Player.h"



void Player::PlacePlayer(int x, int y)
{
	posx = x;
	posy = y;
	life = (x + y) * 2;
}

Player::Player()
{
}


Player::~Player()
{
}
